char webpage[] PROGMEM = R"=====(
<!DOCTYPE HTML><html>
  <head>
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=5, user-scalable=no">
    <style>
    .arrows {
      margin : 0;
      font-size:55px;
      color:red;
    }
    .circularArrows {
      font-size:60px;
      color:darkblue;
    }
    h1 {
      font-family: Georgia, serif;  
      font-style: italic; 
      font-weight: bold;
      margin : 0;
      padding-top:0;
      color: black;
      text-align:center;
    }
    h2 {
      margin : 0; 
      padding-top:0;
      font-size:70px;
      text-align:center;"
    }
    td {
      background-color:black;
      border-radius:25%;
      box-shadow: 5px 5px #888888;
      text-align: center; 
      vertical-align: top;
    }

    td:active {
      transform: translate(5px,5px);
      box-shadow: none; 
    }

    .noselect {
      -webkit-touch-callout: none; /* iOS Safari */
        -webkit-user-select: none; /* Safari */
         -khtml-user-select: none; /* Konqueror HTML */
           -moz-user-select: none; /* Firefox */
            -ms-user-select: none; /* Internet Explorer/Edge */
                user-select: none; /* Non-prefixed version, currently
                                      supported by Chrome and Opera */
    }
    </style>
  <script>
    var Socket;
    function init() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
    }
    function onTouchStartAndEnd(Value_A){
      Socket.send(Value_A);
    }    
  </script>
</head>
 
 <body onload="javascript:init()" class="noselect" align="center" style="background-color:gray">
    <h1>Mustang Racing</h1>
    <h2>&#x1F3CE&#x1F3CE&#x1F3CE;</h2>
  <div>
  <table id="mainTable" style="width:375px; margin:auto;table-layout:fixed" CELLSPACING=9>
    <tr>
      <td ontouchstart='onTouchStartAndEnd("5")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11017;</span></td>
      <td ontouchstart='onTouchStartAndEnd("1")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8679;</span></td>
      <td ontouchstart='onTouchStartAndEnd("6")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11016;</span></td>
    </tr>
    <tr>
      <td ontouchstart='onTouchStartAndEnd("3")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8678;</span></td>
      <td style="background-color:gray;box-shadow:none"></td>
      <td ontouchstart='onTouchStartAndEnd("4")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8680;</span></td>
    </tr>
      
    <tr>
      <td ontouchstart='onTouchStartAndEnd("7")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11019;</span></td>
      <td ontouchstart='onTouchStartAndEnd("2")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8681;</span></td>
      <td ontouchstart='onTouchStartAndEnd("8")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11018;</span></td>
    </tr>    
    <tr>
      <td ontouchstart='onTouchStartAndEnd("9")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="circularArrows" >&#8634;</span></td>
      <td style="background-color:gray;box-shadow:none"></td>
      <td ontouchstart='onTouchStartAndEnd("10")' ontouchcancel='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="circularArrows" >&#8635;</span></td>
    </tr>    
  </table>  
  </div>  
</body onload="javascript:init()">
</html>
)=====";
