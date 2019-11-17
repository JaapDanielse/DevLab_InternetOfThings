// Main HTML Page

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
html {font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
p {display: none;}
.slidecontainer {width: 50%;}
.slider {-webkit-appearance: none; appearance: none; width: 50%; height: 25px; background: #d3d3d3;}
.slider::-webkit-slider-thumb {-webkit-appearance: none; width: 25px; height: 25px; 
  background: #195B6A; cursor: pointer;}
.R::-webkit-slider-thumb {background: #FF0000;}
.G::-webkit-slider-thumb {background: #00FF00;}
.B::-webkit-slider-thumb {background: #0000FF;}
.button {background-color: #195B6A; border: none; color: white; padding: 16px 30px; text-decoration: none; 
  font-size: 20px; margin: 2px; cursor: pointer;}
</style>
<body>

<h1>DevLab Internet of Things</h1>
<hr>

<!-- TIME AND SENSOR DATA -->
<p id="TIME">Time: <span id="CurrentTime">NA</span><br></p>
<p id="TEMP">Temperature: <span id="Temperature">NA</span>&deg;C rel. humidity: <span id="Humidity">NA</span>%<br></p>
<p id="SOIL">Soil: <span id="Soil">NA</span><br></p>
<p id="LIGHT">Light: <span id="Light">NA</span><br></p>
<p id="MOTION">Motion: <span id="Motion">NA</span><br></p>
<script>

setInterval(getData, 2000); // Call getData every 2 seconds

function getData() 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() 
  {
    if (this.readyState == 4 && this.status == 200) 
    {
      var response = JSON.parse(this.responseText);
      if("TIME" in response)
        document.getElementById("CurrentTime").innerHTML = response.TIME;
      if("TEMP" in response)
        document.getElementById("Temperature").innerHTML = response.TEMP;
      if("HUMID" in response)
        document.getElementById("Humidity").innerHTML = response.HUMID;
      if("SOIL" in response)
        document.getElementById("Soil").innerHTML = response.SOIL;
      if("MOTION" in response)
        document.getElementById("Motion").innerHTML = response.MOTION;
      if("LIGHT" in response)
        document.getElementById("Light").innerHTML = response.LIGHT;
      if("RELAY" in response)
        formatButtons(response);
    }
  }
  xhttp.open("GET", "readData", true);
  xhttp.send();
}
</script>
<hr>

<!-- RELAY -->
<p id="RELAY">Relay unit<br>
<button type="button" class="button" id="RCH1" onclick="sendRelayData(1)">CH1</button>
<button type="button" class="button" id="RCH2" onclick="sendRelayData(2)">CH2</button>
<button type="button" class="button" id="RCH3" onclick="sendRelayData(3)">CH3</button>
<button type="button" class="button" id="RCH4" onclick="sendRelayData(4)">CH4</button>
</p>
<script>
function sendRelayData(chanel) 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() 
  {
    if (this.readyState == 4 && this.status == 200) 
    {
      var response = JSON.parse(this.responseText);
      formatButtons(response);
    }
  }
  xhttp.open("GET", "SetRelay?Channel=" + chanel, true);
  xhttp.send();
}

function formatButtons(response)
{
  if(response.RELAY.RCH1 == 1){document.getElementById("RCH1").style.background = "#FF0000"}
  else {document.getElementById("RCH1").style.background = "#195B6A"};
  if(response.RELAY.RCH2 == 1){document.getElementById("RCH2").style.background = "#FF0000"}
  else {document.getElementById("RCH2").style.background = "#195B6A"};
  if(response.RELAY.RCH3 == 1){document.getElementById("RCH3").style.background = "#FF0000"}
  else {document.getElementById("RCH3").style.background = "#195B6A"};
  if(response.RELAY.RCH4 == 1){document.getElementById("RCH4").style.background = "#FF0000"}
  else {document.getElementById("RCH4").style.background = "#195B6A"};
}
</script>

<!-- SERVO -->
<p id="SERVO">Servo: <span id="ServoValue">90</span><br>
<input type="range" min="0" max="180" value="90" id="Servo" class="slider" oninput="sendServoValue(this.value)">
</p>
<script>
function sendServoValue(ServoData) 
{
  document.getElementById("ServoValue").innerHTML = ServoData; 
  var xhttp = new XMLHttpRequest();   
  xhttp.open("GET", "SetServo?ServoData="+ServoData, true);
  xhttp.send()
}
</script>

<!-- RGBLED -->
<p id="RGBLED">RGB Led R:<span id="RLedV">0</span> G:<span id="GLedV">0</span> B:<span id="BLedV">0</span><br>
<input type="range" min="0" max="255" value="0" id="RLed" class="slider R" oninput="sendRGBData()">
<input type="range" min="0" max="255" value="0" id="GLed" class="slider G" oninput="sendRGBData()">
<input type="range" min="0" max="255" value="0" id="BLed" class="slider B" oninput="sendRGBData()">
</p>
<script>
function sendRGBData() 
{
  var RValue = document.getElementById('RLed').value;
  var GValue = document.getElementById('GLed').value;
  var BValue = document.getElementById('BLed').value;
  document.getElementById("RLedV").innerHTML = RValue;
  document.getElementById("GLedV").innerHTML = GValue;
  document.getElementById("BLedV").innerHTML = BValue;
  var xhttp = new XMLHttpRequest();   
  xhttp.open("GET", "SetRGBLed?R="+RValue+"&G="+GValue+"&B="+BValue, true);
  xhttp.send()
}
</script>

<script>
document.addEventListener("DOMContentLoaded", function(event) 
{ 
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() 
  {
    if (this.readyState == 4 && this.status == 200) 
    {
      var response = JSON.parse(this.responseText);
      for (var key in response)
      {
        var o = document.getElementById(key);
        if(o != null)
          o.style.display = 'block';
      }
    }
  }
  xhttp.open("GET", "readData", true);
  xhttp.send();  
});
</script>
</body>
</html>
)=====";
