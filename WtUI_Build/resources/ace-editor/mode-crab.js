//DEFINING HIGHLIGHT RULES, CUSTOMIZED CRAB 2.0 RULES.
ace.define("ace/mode/crab_highlight_rules", ["require", "exports", "module", "ace/lib/oop", "ace/mode/text_highlight_rules"], function (require, exports, module) {
    "use strict";

var oop = require("../lib/oop");
//WILL BE CALLED IN THE MAIN TO BE IMPLIED IN THE EDITOR.
var TextHighlightRules = require("./text_highlight_rules").TextHighlightRules;


//NAME OF THE VARIABLE WHICH WE WILL INHERIT FROM.
var Crab2HighlightRules = function() {
    
    //**IMPORTANT COMMENTARY**
    // regexp must not have capturing parentheses. Use (?:) instead.
    // regexps are ordered -> the first match is used
    //**IMPORTANT COMMENTARY**


//SCANNING OF THE WORDS INPUTTED BY THE USER STARTS AT THIS CODING LIVE.
//"start" IS THE BEGINNING OF THE SCANNING.
    this.$rules = { start: 
       [ 
           
           //THIS TOKEN REPRESENTS THE ALL THE POSSBILE OPERATORS THAT CAN BE USED.
           //HAS TO BE CASE SENSITIVE.
           { token: 'keyword.control.assembly',
           regex: '\\b(?:getb|putb|setp|movp|getm|putm|assn|copy|swap|push|pop|add|mul|idiv|abs|rnd|sin|pow|log|and|not|less|equal|ifel|whil)\\b',
           caseInsensitive: true,
           next : 'variable.parameter.register.assembly'|'constant.character.decimal.assembly'
           },
           
           
           
           //THIS TOKEN REPRESENTS THE POSSIBLE OPERANDS THAT THE OPERATOR CAN USE.
           //HAS TO BE CASE SENSITIVE.
         { token: 'variable.parameter.register.assembly',
           regex: '\\b(?:r0| r1| r2| r3| a0| a1| a2| a2)\\b',
           caseInsensitive: true,
           next : 'start'},
           
           
           //THIS REPRESENTS THE SCALAR DECIMAL VALUES THAT USER CAN USE WITH THE OPERATORS.
         { token: 'constant.character.decimal.assembly',
           regex: '\\b[0-9]+\\b' },
           
           
           //THIS PART COVERS THE STRING.
           //TWO PARTS ARE COVERED : GOING BY "" AND ''.
         { token: 'string.assembly', regex: /'([^\\']|\\.)*'/ },
         { token: 'string.assembly', regex: /"([^\\"]|\\.)*"/ },
        
         
         
         //THIS PART COVERS THE POSSIBLE COMMENTARY THAT THE USER CAN INPUT.
         { token: 'comment.assembly', regex: ';.*$' } ] 
         
         
         
    }
    
    this.normalizeRules();
};







//WE TRANFER THE HIGHLIGHT RULES TO "TEXTHIGHLIGHTRULES",
//WHICH WILL BE USED, CALLED, IN THE MAIN OF THE ACE MAIN EDITOR.
oop.inherits(Crab2HighlightRules, TextHighlightRules);

//eEXPORT INFORMATION
exports.Crab2HighlightRules = Crab2HighlightRules;
});
