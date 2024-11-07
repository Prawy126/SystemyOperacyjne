
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="x-ua-compatible" content="ie=edge">
        <meta name="google-site-verification"
              content="m41-YA2o4kXb32RmyuClA1zAXZCyaGaDEUj1QIc5bmc" />
        <title>
            dpaste: addusers
        </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="apple-touch-icon" sizes="180x180" href="https://dpaste.b-cdn.net/static/pastebin/apple-touch-icon.png">
        <link rel="icon" type="image/png" sizes="16x16" href="https://dpaste.b-cdn.net/static/pastebin/favicon-16x16.png">
        <link rel="icon" type="image/png" sizes="32x32" href="https://dpaste.b-cdn.net/static/pastebin/favicon-32x32.png">
        <link rel="icon" type="image/x-icon" href="https://dpaste.b-cdn.net/static/pastebin/favicon.ico">
        <link rel="manifest" href="https://dpaste.b-cdn.net/static/pastebin/site.webmanifest">
        <link rel="me" href="https://fosstodon.org/@dpaste">
        <link rel="stylesheet" href="https://dpaste.b-cdn.net/static/pastebin/css/normalize.css">
        <link rel="stylesheet" href="https://dpaste.b-cdn.net/static/pastebin/css/skeleton.css">
        <link rel="stylesheet" href="https://dpaste.b-cdn.net/static/pastebin/css/main.css">
        <link href="https://fonts.googleapis.com/css2?family=Fira+Sans:wght@400;700&amp;display=swap" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=Fira+Mono" rel="stylesheet">
        <script src="https://unpkg.com/htmx.org@2.0.2" integrity="sha384-Y7hw+L/jvKeWIRRkqWYfPcvVxHzVzn5REgzbawhxAuQGwX1XWe70vji+VSeHOThJ" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
        <script defer src="https://media.ethicalads.io/media/client/ethicalads.min.js"></script>
        <script>
            function key(event, letter) {
                return (event.charCode == letter.charCodeAt() || event.charCode == letter.charCodeAt() + 32)
            }
        </script>
        <script>
            
    function key(event, letter) {
      return (event.charCode == letter.charCodeAt() || event.charCode == letter.charCodeAt() + 32)
    }

    function subview_redirect(path_end) {
      let base = location.pathname;
      // Drop extension unless we're previewing
      if (path_end !== "-preview") { base = base.substring(0, base.lastIndexOf('.')) || base }
      location.href = base + path_end;
    }

    function indicate_wrap() {
      $("#softwrap_toggle").text("UNWRAP");
      location.hash = "wrap";
    }
    
    function indicate_unwrap() {
      $("#softwrap_toggle").text("SOFT WRAP");
      location.hash = "";
    }

    function softwrap_toggle() {
      $("pre").toggleClass("softwrap")
      $(".linenodiv").toggle()
      if ($("#softwrap_toggle").text() == "SOFT WRAP") {
        indicate_wrap()
      } else {
        indicate_unwrap()
      }
    }

    function mark_linked_line() {
      $('.linemark').remove();
      $('a[href="' + location.hash + '"]').after('<svg height="10" width="16" class="linemark"> <polygon points="3,0 15,4 3,9" style="fill:#99f" /></svg>');
    }

    function copy_to_clipboard() {
      if (!navigator.clipboard) {
        console.log("Clipboard API not available in this browser")
        return
      }
      try {
        // Next three lines: decode-entities hack (from https://stackoverflow.com/a/3700369)
        var tmp = document.createElement('textarea')
        tmp.innerHTML = $('#raw-content').html()
        navigator.clipboard.writeText(tmp.value)
        $('#copy-success').show()
      } catch (err) {
        console.error('Copying raw content failed: ', err)
      }

    }
    $(document).ready(function() {
      window.onhashchange = mark_linked_line
      if (location.hash == "#wrap") {
        softwrap_toggle();
        indicate_wrap();
      }
      if (location.hash.indexOf("#line-") === 0) {
        mark_linked_line();
      }
      $("#softwrap_toggle").click(softwrap_toggle);
      $('#copy-button').click(copy_to_clipboard)
    });
    $(document).keypress(function(event) {
      if (key(event, 'W')) { softwrap_toggle(); }
       // For pastes only, not diffs
        if (key(event, 'C')) { copy_to_clipboard() }
        if (key(event, 'D')) { subview_redirect('/duplicate/') }
        if (key(event, 'R')) { subview_redirect('.txt') }
        
      
       // For owner only
        if (key(event, 'E')) { subview_redirect('/properties/') }
      
    });
    
      
      
      $(document).keyup(function(event) {
        if (event.keyCode == 8 || event.keyCode == 46) { subview_redirect('/delete/') }
      });
    

        </script>
        <style>
    pre { line-height: 125%; }
td.linenos .normal { color: inherit; background-color: transparent; padding-left: 5px; padding-right: 5px; }
span.linenos { color: inherit; background-color: transparent; padding-left: 5px; padding-right: 5px; }
td.linenos .special { color: #000000; background-color: #ffffc0; padding-left: 5px; padding-right: 5px; }
span.linenos.special { color: #000000; background-color: #ffffc0; padding-left: 5px; padding-right: 5px; }
.highlight .hll { background-color: #ffffcc }
.highlight { background: #f8f8f8; }
.highlight .c { color: #3D7B7B; font-style: italic } /* Comment */
.highlight .err { border: 1px solid #FF0000 } /* Error */
.highlight .k { color: #008000; font-weight: bold } /* Keyword */
.highlight .o { color: #666666 } /* Operator */
.highlight .ch { color: #3D7B7B; font-style: italic } /* Comment.Hashbang */
.highlight .cm { color: #3D7B7B; font-style: italic } /* Comment.Multiline */
.highlight .cp { color: #9C6500 } /* Comment.Preproc */
.highlight .cpf { color: #3D7B7B; font-style: italic } /* Comment.PreprocFile */
.highlight .c1 { color: #3D7B7B; font-style: italic } /* Comment.Single */
.highlight .cs { color: #3D7B7B; font-style: italic } /* Comment.Special */
.highlight .gd { color: #A00000 } /* Generic.Deleted */
.highlight .ge { font-style: italic } /* Generic.Emph */
.highlight .ges { font-weight: bold; font-style: italic } /* Generic.EmphStrong */
.highlight .gr { color: #E40000 } /* Generic.Error */
.highlight .gh { color: #000080; font-weight: bold } /* Generic.Heading */
.highlight .gi { color: #008400 } /* Generic.Inserted */
.highlight .go { color: #717171 } /* Generic.Output */
.highlight .gp { color: #000080; font-weight: bold } /* Generic.Prompt */
.highlight .gs { font-weight: bold } /* Generic.Strong */
.highlight .gu { color: #800080; font-weight: bold } /* Generic.Subheading */
.highlight .gt { color: #0044DD } /* Generic.Traceback */
.highlight .kc { color: #008000; font-weight: bold } /* Keyword.Constant */
.highlight .kd { color: #008000; font-weight: bold } /* Keyword.Declaration */
.highlight .kn { color: #008000; font-weight: bold } /* Keyword.Namespace */
.highlight .kp { color: #008000 } /* Keyword.Pseudo */
.highlight .kr { color: #008000; font-weight: bold } /* Keyword.Reserved */
.highlight .kt { color: #B00040 } /* Keyword.Type */
.highlight .m { color: #666666 } /* Literal.Number */
.highlight .s { color: #BA2121 } /* Literal.String */
.highlight .na { color: #687822 } /* Name.Attribute */
.highlight .nb { color: #008000 } /* Name.Builtin */
.highlight .nc { color: #0000FF; font-weight: bold } /* Name.Class */
.highlight .no { color: #880000 } /* Name.Constant */
.highlight .nd { color: #AA22FF } /* Name.Decorator */
.highlight .ni { color: #717171; font-weight: bold } /* Name.Entity */
.highlight .ne { color: #CB3F38; font-weight: bold } /* Name.Exception */
.highlight .nf { color: #0000FF } /* Name.Function */
.highlight .nl { color: #767600 } /* Name.Label */
.highlight .nn { color: #0000FF; font-weight: bold } /* Name.Namespace */
.highlight .nt { color: #008000; font-weight: bold } /* Name.Tag */
.highlight .nv { color: #19177C } /* Name.Variable */
.highlight .ow { color: #AA22FF; font-weight: bold } /* Operator.Word */
.highlight .w { color: #bbbbbb } /* Text.Whitespace */
.highlight .mb { color: #666666 } /* Literal.Number.Bin */
.highlight .mf { color: #666666 } /* Literal.Number.Float */
.highlight .mh { color: #666666 } /* Literal.Number.Hex */
.highlight .mi { color: #666666 } /* Literal.Number.Integer */
.highlight .mo { color: #666666 } /* Literal.Number.Oct */
.highlight .sa { color: #BA2121 } /* Literal.String.Affix */
.highlight .sb { color: #BA2121 } /* Literal.String.Backtick */
.highlight .sc { color: #BA2121 } /* Literal.String.Char */
.highlight .dl { color: #BA2121 } /* Literal.String.Delimiter */
.highlight .sd { color: #BA2121; font-style: italic } /* Literal.String.Doc */
.highlight .s2 { color: #BA2121 } /* Literal.String.Double */
.highlight .se { color: #AA5D1F; font-weight: bold } /* Literal.String.Escape */
.highlight .sh { color: #BA2121 } /* Literal.String.Heredoc */
.highlight .si { color: #A45A77; font-weight: bold } /* Literal.String.Interpol */
.highlight .sx { color: #008000 } /* Literal.String.Other */
.highlight .sr { color: #A45A77 } /* Literal.String.Regex */
.highlight .s1 { color: #BA2121 } /* Literal.String.Single */
.highlight .ss { color: #19177C } /* Literal.String.Symbol */
.highlight .bp { color: #008000 } /* Name.Builtin.Pseudo */
.highlight .fm { color: #0000FF } /* Name.Function.Magic */
.highlight .vc { color: #19177C } /* Name.Variable.Class */
.highlight .vg { color: #19177C } /* Name.Variable.Global */
.highlight .vi { color: #19177C } /* Name.Variable.Instance */
.highlight .vm { color: #19177C } /* Name.Variable.Magic */
.highlight .il { color: #666666 } /* Literal.Number.Integer.Long */
    .linenos { padding-right: 0 }
    .softwrap { white-space: pre-wrap; }
    h1 i { color: #888;}
    td.code { padding-left: 0 }
    #copy-success { color: #fff; font-weight: bold }
</style>
        
    <link href="https://cdn.jsdelivr.net/npm/shareon@2/dist/shareon.min.css" rel="stylesheet">
    <script src="https://cdn.jsdelivr.net/npm/shareon@2/dist/shareon.iife.js" type="text/javascript" defer init></script>

    </head>
    
    <body hx-on:keydown="var path=window.location.pathname; if ((event.key=='n' || event.key=='N') && path && path !== '/' && !path.includes('/duplicate/') && !path.includes('/dashboard/') && !path.includes('/accounts/') && !path.includes('/properties/')) { window.location.href = '/'; }">
        <div id="container">
            
            <div class="topbuttons">
                
                    <a href="/accounts/login/"
                       title="Personal dashboard, preferences, API token"
                       class="button"><b>Sign in</b></a>
                
                <a href="/" title="Create a new paste (shortcut: 'N')" class=" button">New</a>
                <a href="/api/v2/"
                   title="Paste creation API, with code samples"
                   class="   button">API</a>
                <a href="/help/"
                   title="Usage tips, shortcuts"
                   class="  button">Help</a>
                <a href="/about/"
                   title="Updates, stats, backstory"
                   class=" button">About</a>
            </div>
            
    

    <h1>addusers</h1>
    

    <div class="row">
        
1.5 KB of <strong>C</strong>

    <br>

Created a minute ago


    —  
    expires in 1 day





    
        <br>
    
    Viewed
    
    1 time


<span style="display:none">
    
        <br>
    
https://dpaste.com/DESEPCX8W</span>

    </div>
    
    
      <div class="row actionbuttons">
    
        <a id="copy-button" title="Copy raw content (shortcut: 'C'">COPY&nbsp;TO&nbsp;CLIPBOARD<span id="copy-success" hidden>&nbsp;📋</span></a>
        <a id="softwrap_toggle"
           title="Toggle visual wrap of long lines (shortcut: 'W')">SOFT WRAP</a>
        <a href="/DESEPCX8W.txt"
           title="Plaintext version (shortcut: 'R')">RAW&nbsp;TEXT</a>
        
        <a href="/DESEPCX8W/duplicate/"
           title="Make a new paste based on this one (shortcut: 'D')">DUPLICATE</a>
        <a href="/DESEPCX8W/diff"
           title="Diff this paste against another one">DIFF</a>
        
    </div>

    <div class="highlight"><table class="highlighttable"><tr><td class="linenos"><div class="linenodiv"><pre><span class="normal"><a href="#line-1"> 1</a></span>
<span class="normal"><a href="#line-2"> 2</a></span>
<span class="normal"><a href="#line-3"> 3</a></span>
<span class="normal"><a href="#line-4"> 4</a></span>
<span class="normal"><a href="#line-5"> 5</a></span>
<span class="normal"><a href="#line-6"> 6</a></span>
<span class="normal"><a href="#line-7"> 7</a></span>
<span class="normal"><a href="#line-8"> 8</a></span>
<span class="normal"><a href="#line-9"> 9</a></span>
<span class="normal"><a href="#line-10">10</a></span>
<span class="normal"><a href="#line-11">11</a></span>
<span class="normal"><a href="#line-12">12</a></span>
<span class="normal"><a href="#line-13">13</a></span>
<span class="normal"><a href="#line-14">14</a></span>
<span class="normal"><a href="#line-15">15</a></span>
<span class="normal"><a href="#line-16">16</a></span>
<span class="normal"><a href="#line-17">17</a></span>
<span class="normal"><a href="#line-18">18</a></span>
<span class="normal"><a href="#line-19">19</a></span>
<span class="normal"><a href="#line-20">20</a></span>
<span class="normal"><a href="#line-21">21</a></span>
<span class="normal"><a href="#line-22">22</a></span>
<span class="normal"><a href="#line-23">23</a></span>
<span class="normal"><a href="#line-24">24</a></span>
<span class="normal"><a href="#line-25">25</a></span>
<span class="normal"><a href="#line-26">26</a></span>
<span class="normal"><a href="#line-27">27</a></span>
<span class="normal"><a href="#line-28">28</a></span>
<span class="normal"><a href="#line-29">29</a></span>
<span class="normal"><a href="#line-30">30</a></span>
<span class="normal"><a href="#line-31">31</a></span>
<span class="normal"><a href="#line-32">32</a></span>
<span class="normal"><a href="#line-33">33</a></span>
<span class="normal"><a href="#line-34">34</a></span>
<span class="normal"><a href="#line-35">35</a></span>
<span class="normal"><a href="#line-36">36</a></span>
<span class="normal"><a href="#line-37">37</a></span>
<span class="normal"><a href="#line-38">38</a></span>
<span class="normal"><a href="#line-39">39</a></span>
<span class="normal"><a href="#line-40">40</a></span>
<span class="normal"><a href="#line-41">41</a></span>
<span class="normal"><a href="#line-42">42</a></span>
<span class="normal"><a href="#line-43">43</a></span>
<span class="normal"><a href="#line-44">44</a></span>
<span class="normal"><a href="#line-45">45</a></span>
<span class="normal"><a href="#line-46">46</a></span>
<span class="normal"><a href="#line-47">47</a></span>
<span class="normal"><a href="#line-48">48</a></span>
<span class="normal"><a href="#line-49">49</a></span>
<span class="normal"><a href="#line-50">50</a></span>
<span class="normal"><a href="#line-51">51</a></span>
<span class="normal"><a href="#line-52">52</a></span>
<span class="normal"><a href="#line-53">53</a></span></pre></div></td><td class="code"><div><pre><span></span><a id="line-1" name="line-1"></a><span class="cp">#include</span><span class="w"> </span><span class="cpf">&lt;stdio.h&gt;</span>
<a id="line-2" name="line-2"></a><span class="cp">#include</span><span class="w"> </span><span class="cpf">&lt;stdlib.h&gt;</span>
<a id="line-3" name="line-3"></a><span class="cp">#include</span><span class="w"> </span><span class="cpf">&lt;string.h&gt;</span>
<a id="line-4" name="line-4"></a>
<a id="line-5" name="line-5"></a><span class="cp">#define MAX_LINE_LENGTH 256</span>
<a id="line-6" name="line-6"></a>
<a id="line-7" name="line-7"></a><span class="kt">void</span><span class="w"> </span><span class="nf">trimNewline</span><span class="p">(</span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">str</span><span class="p">)</span><span class="w"> </span><span class="p">{</span>
<a id="line-8" name="line-8"></a><span class="w">    </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">pos</span><span class="p">;</span>
<a id="line-9" name="line-9"></a><span class="w">    </span><span class="k">if</span><span class="w"> </span><span class="p">((</span><span class="n">pos</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">strchr</span><span class="p">(</span><span class="n">str</span><span class="p">,</span><span class="w"> </span><span class="sc">&#39;\n&#39;</span><span class="p">))</span><span class="w"> </span><span class="o">!=</span><span class="w"> </span><span class="nb">NULL</span><span class="p">)</span><span class="w"> </span><span class="o">*</span><span class="n">pos</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="sc">&#39;\0&#39;</span><span class="p">;</span>
<a id="line-10" name="line-10"></a><span class="w">    </span><span class="k">if</span><span class="w"> </span><span class="p">((</span><span class="n">pos</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">strchr</span><span class="p">(</span><span class="n">str</span><span class="p">,</span><span class="w"> </span><span class="sc">&#39;\r&#39;</span><span class="p">))</span><span class="w"> </span><span class="o">!=</span><span class="w"> </span><span class="nb">NULL</span><span class="p">)</span><span class="w"> </span><span class="o">*</span><span class="n">pos</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="sc">&#39;\0&#39;</span><span class="p">;</span>
<a id="line-11" name="line-11"></a><span class="p">}</span>
<a id="line-12" name="line-12"></a>
<a id="line-13" name="line-13"></a><span class="kt">void</span><span class="w"> </span><span class="nf">addUser</span><span class="p">(</span><span class="k">const</span><span class="w"> </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">username</span><span class="p">,</span><span class="w"> </span><span class="k">const</span><span class="w"> </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">fullname</span><span class="p">,</span><span class="w"> </span><span class="k">const</span><span class="w"> </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">password</span><span class="p">)</span><span class="w"> </span><span class="p">{</span>
<a id="line-14" name="line-14"></a><span class="w">    </span><span class="kt">char</span><span class="w"> </span><span class="n">command</span><span class="p">[</span><span class="n">MAX_LINE_LENGTH</span><span class="p">];</span>
<a id="line-15" name="line-15"></a>
<a id="line-16" name="line-16"></a><span class="w">    </span><span class="n">snprintf</span><span class="p">(</span><span class="n">command</span><span class="p">,</span><span class="w"> </span><span class="k">sizeof</span><span class="p">(</span><span class="n">command</span><span class="p">),</span><span class="w"> </span><span class="s">&quot;sudo useradd -m -c </span><span class="se">\&quot;</span><span class="s">%s</span><span class="se">\&quot;</span><span class="s"> -p $(openssl passwd -1 %s) %s&quot;</span><span class="p">,</span>
<a id="line-17" name="line-17"></a><span class="w">             </span><span class="n">fullname</span><span class="p">,</span><span class="w"> </span><span class="n">password</span><span class="p">,</span><span class="w"> </span><span class="n">username</span><span class="p">);</span>
<a id="line-18" name="line-18"></a><span class="w">    </span>
<a id="line-19" name="line-19"></a><span class="w">    </span><span class="kt">int</span><span class="w"> </span><span class="n">result</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">system</span><span class="p">(</span><span class="n">command</span><span class="p">);</span>
<a id="line-20" name="line-20"></a><span class="w">    </span><span class="k">if</span><span class="w"> </span><span class="p">(</span><span class="n">result</span><span class="w"> </span><span class="o">==</span><span class="w"> </span><span class="mi">-1</span><span class="p">)</span><span class="w"> </span><span class="p">{</span>
<a id="line-21" name="line-21"></a><span class="w">        </span><span class="n">perror</span><span class="p">(</span><span class="s">&quot;Błąd wykonania komendy&quot;</span><span class="p">);</span>
<a id="line-22" name="line-22"></a><span class="w">    </span><span class="p">}</span><span class="w"> </span><span class="k">else</span><span class="w"> </span><span class="k">if</span><span class="w"> </span><span class="p">(</span><span class="n">result</span><span class="w"> </span><span class="o">!=</span><span class="w"> </span><span class="mi">0</span><span class="p">)</span><span class="w"> </span><span class="p">{</span>
<a id="line-23" name="line-23"></a><span class="w">        </span><span class="n">fprintf</span><span class="p">(</span><span class="n">stderr</span><span class="p">,</span><span class="w"> </span><span class="s">&quot;Nie udało się dodać użytkownika: %s</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span><span class="w"> </span><span class="n">username</span><span class="p">);</span>
<a id="line-24" name="line-24"></a><span class="w">    </span><span class="p">}</span><span class="w"> </span><span class="k">else</span><span class="w"> </span><span class="p">{</span>
<a id="line-25" name="line-25"></a><span class="w">        </span><span class="n">printf</span><span class="p">(</span><span class="s">&quot;Użytkownik %s został pomyślnie dodany.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span><span class="w"> </span><span class="n">username</span><span class="p">);</span>
<a id="line-26" name="line-26"></a><span class="w">    </span><span class="p">}</span>
<a id="line-27" name="line-27"></a><span class="p">}</span>
<a id="line-28" name="line-28"></a>
<a id="line-29" name="line-29"></a><span class="kt">int</span><span class="w"> </span><span class="nf">main</span><span class="p">()</span><span class="w"> </span><span class="p">{</span>
<a id="line-30" name="line-30"></a><span class="w">    </span><span class="kt">FILE</span><span class="w"> </span><span class="o">*</span><span class="n">file</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">fopen</span><span class="p">(</span><span class="s">&quot;baza.txt&quot;</span><span class="p">,</span><span class="w"> </span><span class="s">&quot;r&quot;</span><span class="p">);</span>
<a id="line-31" name="line-31"></a><span class="w">    </span><span class="k">if</span><span class="w"> </span><span class="p">(</span><span class="n">file</span><span class="w"> </span><span class="o">==</span><span class="w"> </span><span class="nb">NULL</span><span class="p">)</span><span class="w"> </span><span class="p">{</span>
<a id="line-32" name="line-32"></a><span class="w">        </span><span class="n">perror</span><span class="p">(</span><span class="s">&quot;Nie można otworzyć pliku baza.txt&quot;</span><span class="p">);</span>
<a id="line-33" name="line-33"></a><span class="w">        </span><span class="k">return</span><span class="w"> </span><span class="n">EXIT_FAILURE</span><span class="p">;</span>
<a id="line-34" name="line-34"></a><span class="w">    </span><span class="p">}</span>
<a id="line-35" name="line-35"></a>
<a id="line-36" name="line-36"></a><span class="w">    </span><span class="kt">char</span><span class="w"> </span><span class="n">line</span><span class="p">[</span><span class="n">MAX_LINE_LENGTH</span><span class="p">];</span>
<a id="line-37" name="line-37"></a><span class="w">    </span><span class="k">while</span><span class="w"> </span><span class="p">(</span><span class="n">fgets</span><span class="p">(</span><span class="n">line</span><span class="p">,</span><span class="w"> </span><span class="k">sizeof</span><span class="p">(</span><span class="n">line</span><span class="p">),</span><span class="w"> </span><span class="n">file</span><span class="p">))</span><span class="w"> </span><span class="p">{</span>
<a id="line-38" name="line-38"></a><span class="w">        </span><span class="n">trimNewline</span><span class="p">(</span><span class="n">line</span><span class="p">);</span>
<a id="line-39" name="line-39"></a>
<a id="line-40" name="line-40"></a><span class="w">        </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">username</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">strtok</span><span class="p">(</span><span class="n">line</span><span class="p">,</span><span class="w"> </span><span class="s">&quot;;&quot;</span><span class="p">);</span>
<a id="line-41" name="line-41"></a><span class="w">        </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">fullname</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">strtok</span><span class="p">(</span><span class="nb">NULL</span><span class="p">,</span><span class="w"> </span><span class="s">&quot;;&quot;</span><span class="p">);</span>
<a id="line-42" name="line-42"></a><span class="w">        </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">password</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">strtok</span><span class="p">(</span><span class="nb">NULL</span><span class="p">,</span><span class="w"> </span><span class="s">&quot;;&quot;</span><span class="p">);</span>
<a id="line-43" name="line-43"></a>
<a id="line-44" name="line-44"></a><span class="w">        </span><span class="k">if</span><span class="w"> </span><span class="p">(</span><span class="n">username</span><span class="w"> </span><span class="o">&amp;&amp;</span><span class="w"> </span><span class="n">fullname</span><span class="w"> </span><span class="o">&amp;&amp;</span><span class="w"> </span><span class="n">password</span><span class="p">)</span><span class="w"> </span><span class="p">{</span>
<a id="line-45" name="line-45"></a><span class="w">            </span><span class="n">addUser</span><span class="p">(</span><span class="n">username</span><span class="p">,</span><span class="w"> </span><span class="n">fullname</span><span class="p">,</span><span class="w"> </span><span class="n">password</span><span class="p">);</span>
<a id="line-46" name="line-46"></a><span class="w">        </span><span class="p">}</span><span class="w"> </span><span class="k">else</span><span class="w"> </span><span class="p">{</span>
<a id="line-47" name="line-47"></a><span class="w">            </span><span class="n">fprintf</span><span class="p">(</span><span class="n">stderr</span><span class="p">,</span><span class="w"> </span><span class="s">&quot;Niepoprawny format linii: %s</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span><span class="w"> </span><span class="n">line</span><span class="p">);</span>
<a id="line-48" name="line-48"></a><span class="w">        </span><span class="p">}</span>
<a id="line-49" name="line-49"></a><span class="w">    </span><span class="p">}</span>
<a id="line-50" name="line-50"></a>
<a id="line-51" name="line-51"></a><span class="w">    </span><span class="n">fclose</span><span class="p">(</span><span class="n">file</span><span class="p">);</span>
<a id="line-52" name="line-52"></a><span class="w">    </span><span class="k">return</span><span class="w"> </span><span class="n">EXIT_SUCCESS</span><span class="p">;</span>
<a id="line-53" name="line-53"></a><span class="p">}</span>
</pre></div></td></tr></table></div>

    <div id="raw-content" hidden>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;

#define MAX_LINE_LENGTH 256

void trimNewline(char *str) {
    char *pos;
    if ((pos = strchr(str, &#x27;\n&#x27;)) != NULL) *pos = &#x27;\0&#x27;;
    if ((pos = strchr(str, &#x27;\r&#x27;)) != NULL) *pos = &#x27;\0&#x27;;
}

void addUser(const char *username, const char *fullname, const char *password) {
    char command[MAX_LINE_LENGTH];

    snprintf(command, sizeof(command), &quot;sudo useradd -m -c \&quot;%s\&quot; -p $(openssl passwd -1 %s) %s&quot;,
             fullname, password, username);
    
    int result = system(command);
    if (result == -1) {
        perror(&quot;Błąd wykonania komendy&quot;);
    } else if (result != 0) {
        fprintf(stderr, &quot;Nie udało się dodać użytkownika: %s\n&quot;, username);
    } else {
        printf(&quot;Użytkownik %s został pomyślnie dodany.\n&quot;, username);
    }
}

int main() {
    FILE *file = fopen(&quot;baza.txt&quot;, &quot;r&quot;);
    if (file == NULL) {
        perror(&quot;Nie można otworzyć pliku baza.txt&quot;);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        trimNewline(line);

        char *username = strtok(line, &quot;;&quot;);
        char *fullname = strtok(NULL, &quot;;&quot;);
        char *password = strtok(NULL, &quot;;&quot;);

        if (username &amp;&amp; fullname &amp;&amp; password) {
            addUser(username, fullname, password);
        } else {
            fprintf(stderr, &quot;Niepoprawny format linii: %s\n&quot;, line);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}</div>
    <hr>
    
    
    <div class="shareon">
        <p>Share:</p>
        <button class="mastodon"></button>
        <button class="reddit"></button>
        <button class="copy-url"></button>
    </div>
    <hr>

<div style="right: 0px; position: absolute">
    <div data-ea-publisher="dpaste"
         data-ea-type="text"
         data-ea-keywords="programming|C"></div>
</div>


        </div>
        
        
        <script>
            window.fwSettings={'widget_id':22000000180 };
            !function(){if("function"!=typeof window.FreshworksWidget){var n=function(){n.q.push(arguments)};n.q=[],window.FreshworksWidget=n}}();
        </script>
        <script defer src='https://widget.freshworks.com/widgets/22000000180.js'></script>
    </body>
</html>
