define(function(require, exports, module) {
"use strict";

var oop = require("../lib/oop");
// defines the parent mode
var TextMode = require("./text").Mode; //WE NEED TO DEFINE THIS FIRST. //****ONLY IF THE LANGUAGE THAT WE USE DEPENDS OF ANOTHER ALREADY EXISTING LANGUAGE.****
var Tokenizer = require("../tokenizer").Tokenizer;
var MatchingBraceOutdent = require("./matching_brace_outdent").MatchingBraceOutdent;

//PART 1: EXPORT THE FILES THAT WE HAVE CREATED WITH THE RULES OF OUR OWN LANGUAGE. INTO A VARIABLE THAT WILL BE POINTED AT LATER ON.
// defines the language specific highlighters and folding rules
var MyNewHighlightRules = require("./mynew_highlight_rules").MyNewHighlightRules;     //TO BE DEFINED. THIS IS POINTING TO THE FILE THAT WE CREATE WITH THE HIGHLIGHTS RULES.
var MyNewFoldMode = require("./folding/mynew").MyNewFoldMode; //TO BE DEFINED. THIS IS POINTING TO THE FILE WITH OUR FOLDING RULES OF OUR OWN.

//PART 2: POINT TO THESE RULES WITH THE HELP OF MODE FUNTION, CREATE THE OBJECTS OF IT.
var Mode = function() {
    // set everything up
    this.HighlightRules = MyNewHighlightRules; //WE WILL HAVE TO DEFINE “MYNEWHIGHLIGHTRULES” RULES HERE.
    this.$outdent = new MatchingBraceOutdent(); //WE WILL HAVE TO DEFINE THE IDENTATION RULES AS WELL.
    this.foldingRules = new MyNewFoldMode(); //WE WILL HAVE TO DEFINE THE FOLDING RULES AS WELL.
};

//****ONLY IF THE LANGUAGE THAT WE USE DEPENDS OF ANOTHER ALREADY EXISTING LANGUAGE.****
oop.inherits(Mode, TextMode); //CAN INHERIT FROM THE SAME LANGUAGE OF ANOTHER LANGUAGE AS WELL.


(function() {

    //PART 3.1: DEFINE WHAT IS THE METHOD/SYNTAX THE USER CAN USE TO DEFINE HIS COMMENTS.
    // configure comment start/end characters
    this.lineCommentStart = "//";
    this.blockComment = {start: "/*", end: "*/"};
    
    //PART 3.2: DEFINE THE LOGIC BEHIND THE INTEND AND OUTDENT.
    // special logic for indent/outdent. 
    // By default ace keeps indentation of previous line
    this.getNextLineIndent = function(state, line, tab) {
        var indent = this.$getIndent(line);
        return indent;
    };

    this.checkOutdent = function(state, line, input) {
        return this.$outdent.checkOutdent(line, input);
    };

    this.autoOutdent = function(state, doc, row) {
        this.$outdent.autoOutdent(doc, row);
    };
    
    //PART 3.5: THE “CREATEWORKER” WILL VERIFY IN A LIVE METHOD HOW TO HIGHLIGHT THE LANGUAGE.
    // create worker for live syntax checking
    this.createWorker = function(session) 
    {
        var worker = new WorkerClient(["ace"], "ace/mode/mynew_worker", "NewWorker");
        worker.attachToDocument(session.getDocument());
        worker.on("errors", function(e) 
        {
            session.setAnnotations(e.data);
        });
        return worker;
    };
    
}).call(Mode.prototype);

exports.Mode = Mode;
});

//THIS WHOLE FIRST PART OF THE CODING PROCESS IS PRETTY SIMPLE: IT CONTAIN THE PATH TO THE LANGUAGE SYNTAX, TO THE INDENTATION RULES AND THE FOLDING RULES. 
//HERE THE TEXT MODE EXPORT IS ONLY USED IF OUR LANGUAGE INHERITS THE RULES OF AN ALREADY CREATED LANGUAGE.
//ALL CREATED MODES AND HIGHLIGHTS CAN BE FOUND @ lib/ace/mode. GITHUB NEEDS TO BE INSTALLED SOON.*
//NOW WE GO TO DEFINE mynew_highlight_rules.js.





