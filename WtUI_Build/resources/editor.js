var Editor;
$.getScript('//ace-editor/ace.js',function(){
  $.getScript('//ace-editor/ext-language_tools.js',function(){

      ace.require("ace/ext/language_tools");
    
      Editor = ace.edit("Editor");
      Editor.getSession().setMode("ace/mode/html");
      Editor.setTheme("ace/theme/merbivore");
      Editor.setOptions({
            enableBasicAutocompletion: true,
            enableSnippets: true
      });
      Editor.commands.on("afterExec", function(e){ 
        if (e.command.name == "insertstring"&&/^[\<.]$/.test(e.args)) { 
        	Editor.execCommand("startAutocomplete") 
     	} 
	  });
      Editor.setShowPrintMargin(false);
      Editor.setHighlightActiveLine(false);
      
      // code insert examples
      $('#btnContainer').click(function(){
          Editor.insert("<div class=\"container\"></div>");
      });
    
      $('#btnRow').click(function(){
          Editor.insert("<div class=\"row\"></div>");
      });
  });
});


