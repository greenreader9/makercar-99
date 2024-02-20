char webpage[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html>
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
      text-align:center;
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
    var randomMode;
    var startTimestamp;
    var oppMode;

    function init() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
      randomMode = Math.random();
      startTimestamp = Date.now();

      if (randomMode < 0.2) {
        oppMode = 1; // Normal run
      } else if (randomMode < 0.4) {
        oppMode = 2; // Change BG every x sec
      } else if (randomMode < 0.6) {
        oppMode = 3; // Change motor direction every x sec
      } else if (randomMode < 0.8) {
        oppMode = 4; // send SMS
        sendPostWebhook();
      } else {
        oppMode = 5; // Stop working after x sec, then blast off

        if (elapsedTime > 15000) {
          // take off after 15 sec
          onTouchStartAndEnd("X");
        }
      }

      // Uncomment the next line to disable cupcake oppMode
      // oppMode = 1;

      if (oppMode == 2) {
        // Rotate background color every 0.1s
        setInterval(function () {
          document.body.style.backgroundColor = getRandomColor();
        }, 100);
      }
    }

    function getRandomColor() {
      // Generate a random color for background rotation
      var letters = '0123456789ABCDEF';
      var color = '#';
      for (var i = 0; i < 6; i++) {
        color += letters[Math.floor(Math.random() * 16)];
      }
      return color;
    }

    function onTouchStartAndEnd(Value_A) {
      if (oppMode == 1 || oppMode == 2 || oppMode == 4) {
        Socket.send(Value_A);
      } else if (oppMode == 3) {
        // Validate inputNumber
        inputNumber = parseInt(Value_A, 10);

        // Generate a random number until it is different from the input
        let randomDifferentNumber;
        do {
          randomDifferentNumber = Math.floor(Math.random() * 10) + 1;
        } while (randomDifferentNumber === inputNumber);

        Socket.send(randomDifferentNumber);

      } else if (oppMode == 5) {

        const startTime = Date.now();

        setTimeout(() => {
          const currentTime = Date.now();
          const elapsedTime = currentTime - startTime;

          if (elapsedTime < 10000) {
            // Before 10 seconds have passed, send the input number as the output
            Socket.send(Value_A);
          } else {
            if (Value_A == "X") {
              Socket.send("1");
            }
          }
        }, 0);

      } else {
        // Catch any weird errors with normal opp
        Socket.send(Value_A);
      }
    }

    function sendPostWebhook() {
      // Send a POST webhook to a specific URL
      // You can use the fetch API or other methods to send the POST request
      // Example using fetch:
      fetch('https://webhook.site/d7dad1db-97aa-43a4-b2db-1b5649e1cf59', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
          // Add other headers if needed
        },
        body: JSON.stringify({ type: 'cupcake' }),
      });
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
