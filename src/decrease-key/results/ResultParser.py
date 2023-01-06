l1 = list(range(10, 91, 10))
l2 = list(range(100, 901, 100))
l3 = list(range(1000, 100001, 1000))


l = l1+l2+l3

with open("results.csv", "w") as csv:
    csv.write("\"N\", \"real\", \"user\", \"sys\"\n")
    for i in l:
        for t in range(1, 6):
            dict = {
                "num": i,
                "real": [],
                "user": [],
                "sys": []
            }
            print("\rAbriendo archivo {}.txt".format(i))
            j = 0
            with open("result_files/{i}_{t}.txt".format(i=i, t=t), "r") as f:
                str = []
                for line in f.readlines():
                    print("\rAnalizando elemento {}".format(j))
                    str = line
                    if (str == "\n"):
                        continue
                    str = str.split("\t")
                    mode = str[0]
                    time = str[1]
                    time = time.split("m")
                    s = float(time[1].replace("s", "").replace(
                        "\n", "").replace(",", ".")) * 100
                    s += float(time[0])*100*60
                    dict.get(mode).append(s)
                    j += 1

                csv.write("{num},{real},{user},{sys}\n".format(
                    num=dict.get("num"),
                    real=sum(dict.get("real"))/len(dict.get("real")),
                    user=sum(dict.get("user"))/len(dict.get("user")),
                    sys=sum(dict.get("sys"))/len(dict.get("sys"))))
with open("average.csv", "w") as csv:
    csv.write("\"N\", \"real\", \"user\", \"sys\"\n")
    dict = {
        "num": 0,
        "real": [],
        "user": [],
        "sys": []
    }
    with open("results.csv", "r") as res:
        str = res.readline()

        for line in res.readlines():
            str = line
            str = str.split(",")
            if (float(str[0]) == dict["num"]):
                dict.get("real").append(float(str[1]))
                dict.get("user").append(float(str[2]))
                dict.get("sys").append(float(str[3]))
            else:
                if dict["num"] != 0:
                    csv.write("{num},{real},{user},{sys}\n".format(
                        num=dict.get("num"),
                        real=sum(dict.get("real"))/len(dict.get("real")),
                        user=sum(dict.get("user"))/len(dict.get("user")),
                        sys=sum(dict.get("sys"))/len(dict.get("sys"))))

                dict["num"] = float(str[0])
                dict["real"] = [float(str[1])]
                dict["user"] = [float(str[2])]
                dict["sys"] = [float(str[3])]
        csv.write("{num},{real},{user},{sys}\n".format(
            num=dict.get("num"),
            real=sum(dict.get("real"))/len(dict.get("real")),
            user=sum(dict.get("user"))/len(dict.get("user")),
            sys=sum(dict.get("sys"))/len(dict.get("sys"))))
