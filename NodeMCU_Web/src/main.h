const char index_html[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html lang="en">

<header>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Nguyen Duc Canh</title>
    <link rel="icon" href="https://media.istockphoto.com/id/1156597690/vi/vec-to/icon-vector-theo-phong-c%C3%A1ch-ph%E1%BA%B3ng-tr%C3%A1i-tim-bi%E1%BB%83u-t%C6%B0%E1%BB%A3ng-t%C3%ACnh-y%C3%AAu-ng%C3%A0y-valentine-%C4%91%C6%B0%E1%BB%A3c-c%C3%A1ch-ly.jpg?s=170667a&w=0&k=20&c=ps7nhL2Gn9ZBFcYhTnj6v_YWnHSs5fjS_KggViGr75o=">
    <link rel="stylesheet" href="./asscet/scc/style.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
    .contaner {}

.header {
    background-color: rgb(152, 192, 229);
}

.header_IOT {
    padding-top: 10px;
    text-align: center;
    font-style: unset;
    font-size: 23px;
    font-weight: bold;
    color: brown;
}

.header_name {
    display: flex;
}

.name_1 {
    width: 50%;
    text-align: center;
    font-style: unset;
    color: rgb(20, 66, 111);
}

.name_2 {
    width: 50%;
    text-align: center;
    font-style: unset;
    color: rgb(20, 66, 111);
}

.content {
    display: flex;
    margin-top: 20px;
}

.content_left {
    width: 50%;
    margin-right: 20px;
}

.content_left_title {
    background-color: rgb(152, 192, 229);
    color: black;
    padding: 10px;
    padding-left: 35px;
    font-style: italic;
}

.content_left_control {
    background-color: rgb(214, 227, 234);
}

.content_left_control_light {
    padding: 10px;
    display: flex;
    justify-content: space-around;
}

.fa-lightbulb-o {
    margin-right: 20px;
}

.content_right {}

.content_right_control {
    background-color: rgb(214, 227, 234);
}

.content_right_control_sub {}

.right {
    margin-left: 43px;
    padding: 11.5px;
}

.fa-thermometer-empty {
    margin-right: 20px;
}

.light {
    margin-left: -25px;
}

.temp {
    margin-left: 70px;
}

.fa-solid {}

.BTN_ON {}

.ONN {
    border-radius: 5px;
}

.OFF {
    border-radius: 5px;
}

.BTN_OFF {}

.OFF {}

.cursor {
    cursor: pointer;
}

.OFF:hover {
    background-color: rgb(189, 37, 37);
}

.OFF:focus {
    background-color: rgb(189, 37, 37);
}

.ONN:hover {
    background-color: rgb(31, 155, 68);
}

.ONN:focus {
    background-color: rgb(31, 155, 68);
}


/*.ONN:active {
    background-color: rgb(11, 88, 47);
}*/

.content_right {
    width: 50%;
    margin-left: 20px;
}

.anh {
    position: absolute;
    top: 10px;
    left: 10px;
    width: 80px;
    border-radius: 3px;
}

.anh1 {
    position: absolute;
    top: 10px;
    right: 10px;
    width: 80px;
    border-radius: 3px;
}

.anh:hover {
    cursor: pointer;
    opacity: 0.8;
}

.body {
    position: relative;
}
</style>
</header>


<body>
    <div class="contaner">

        <div class="header">

            <div class="header_IOT"> IoT UTC2</div>
            <div class="header_name">
                <p class="name_1">
                    ĐTTHCN-K60
                </p>
                <p class="name_2">
                    Nguyen Duc Canh
                </p>
            </div>

        </div>

        <div class="content">
            <div class="content_left">
                <div class="content_left_title"> Control panel</div>
                <div class="content_left_control">

                    <div class="content_left_control_light">
                        <div class="light">
                            <i class="fa fa-lightbulb-o" aria-hidden="true"></i>Light 1
                        </div>
                        <div class="BTN_ON">
                            <button class=" ONN cursor" onclick="bat()">ON</button>
                        </div>
                        <div class="BTN_OFF">
                            <button class="OFF cursor" onclick="tat()">OFF</button>
                        </div>
                    </div>
                    <div class="content_left_control_light">

                        <div class="light">
                            <i class="fa fa-lightbulb-o" aria-hidden="true"></i></i> Light 2
                        </div>
                        <div class="BTN_ON">
                            <button class=" ONN cursor">ON</button>

                        </div>
                        <div class="BTN_OFF">
                            <button class="OFF cursor">OFF</button>
                        </div>
                    </div>

                    <div class="content_left_control_light">

                        <div class="light">
                            <i class="fa fa-lightbulb-o" aria-hidden="true"></i> Light 3
                        </div>
                        <div class="BTN_ON">
                            <button class="ONN cursor">ON</button>

                        </div>
                        <div class="BTN_OFF">
                            <button class="OFF cursor">OFF</button>
                        </div>
                    </div>


                </div>

            </div>
            <div class="content_right">
                <div class="content_left_title"> Subscription Panel
                </div>
                <div class="content_right_control">

                    <div class="content_right_control_sub">
                        <div class="right">
                            <i class="fa fa-thermometer-empty" aria-hidden="true"></i> Temprature
                            <span class="temp" id="temperature">%TEMPERATURE%</span>
                            <sup class="units">&deg;C</sup>
                        </div>
                    </div>
                    <div class="content_right_control_sub">
                        <div class="right">
                            <i class="fa fa-thermometer-empty" aria-hidden="true"></i> HUMIDITY
                            <span class="temp" id="humidity">%HUMIDITY%</span>
                            <sup class="units">&percnt;</sup>
                        </div>
                    </div>
                    <div class="content_right_control_sub">
                        <div class="right">
                            <i class="fa fa-thermometer-empty" aria-hidden="true"></i> Temprature 1
                        </div>
                    </div>

                </div>

            </div>
        </div>

    </div>
    </div>

    <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR0yHEufecLmQMPhcJeLdqwJvJLKwj3tioE4ZpulWgAbsws9fO9SUq0RWkhmEOd9Rx0MT4&usqp=CAU" alt="" class="anh">
    <img src="" alt="" class="anh1">
</body>
<script>
    function bat() {
        var xhttp = new XMLHttpRequest();
        xhttp.open('GET', '/on', true);
        xhttp.send();
    }

    function tat() {
        var xhttp = new XMLHttpRequest();
        xhttp.open('GET', '/off', true);
        xhttp.send();
    }

    setInterval(function() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("temperature").innerHTML = this.responseText;
            }
        };
        xhttp.open("GET", "/temperature", true);
        xhttp.send();
    }, 10000);
    setInterval(function() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("humidity").innerHTML = this.responseText;
            }
        };
        xhttp.open("GET", "/humidity", true);
        xhttp.send();
    }, 10000);
</script>

</html>

)rawliteral";