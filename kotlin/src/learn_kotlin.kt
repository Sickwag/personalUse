Container(
    width: 375,
    height: 812,
    color: Colors.white,
    child: Stack(
        children:[
            Container(
                width: 375,
                height: 812,
                padding: const EdgeInsets.only(top: 40, ),
                child: Column(
                    mainAxisSize: MainAxisSize.min,
                    mainAxisAlignment: MainAxisAlignment.start,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children:[
                        Container(
                            width: double.infinity,
                            padding: const EdgeInsets.symmetric(horizontal: 24, ),
                            child: Row(
                                mainAxisSize: MainAxisSize.min,
                                mainAxisAlignment: MainAxisAlignment.start,
                                crossAxisAlignment: CrossAxisAlignment.center,
                                children:[
                                    Container(
                                        width: 48,
                                        height: 48,
                                        child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.center,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Container(
                                                    width: 48,
                                                    height: 48,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(44),
                                                    ),
                                                    child: FlutterLogo(size: 48),
                                                ),
                                            ],
                                        ),
                                    ),
                                    SizedBox(width: 12),
                                    Column(
                                        mainAxisSize: MainAxisSize.min,
                                        mainAxisAlignment: MainAxisAlignment.start,
                                        crossAxisAlignment: CrossAxisAlignment.start,
                                        children:[
                                            SizedBox(
                                                width: 207,
                                                child: Text(
                                                    "Good Evening",
                                                    style: TextStyle(
                                                        color: Color(0xff9ca2ba),
                                                        fontSize: 14,
                                                    ),
                                                ),
                                            ),
                                            SizedBox(height: 4),
                                            SizedBox(
                                                width: 207,
                                                child: Text(
                                                    "Nicolas Smith",
                                                    style: TextStyle(
                                                        color: Color(0xff212946),
                                                        fontSize: 18,
                                                        fontFamily: "Poppins",
                                                        fontWeight: FontWeight.w600,
                                                    ),
                                                ),
                                            ),
                                        ],
                                    ),
                                    SizedBox(width: 12),
                                    Container(
                                        width: 48,
                                        height: 48,
                                        child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.center,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Container(
                                                    width: 48,
                                                    height: 48,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(56),
                                                        border: Border.all(color: Color(0x195b6589), width: 1, ),
                                                        color: Colors.white,
                                                    ),
                                                    padding: const EdgeInsets.all(12),
                                                    child: Row(
                                                        mainAxisSize: MainAxisSize.min,
                                                        mainAxisAlignment: MainAxisAlignment.center,
                                                        crossAxisAlignment: CrossAxisAlignment.center,
                                                        children:[
                                                            Container(
                                                                width: 24,
                                                                height: 24,
                                                                decoration: BoxDecoration(
                                                                    borderRadius: BorderRadius.circular(8),
                                                                ),
                                                                child: FlutterLogo(size: 24),
                                                            ),
                                                        ],
                                                    ),
                                                ),
                                            ],
                                        ),
                                    ),
                                ],
                            ),
                        ),
                        SizedBox(height: 32),
                        Container(
                            width: double.infinity,
                            padding: const EdgeInsets.symmetric(horizontal: 24, ),
                            child: Row(
                                mainAxisSize: MainAxisSize.min,
                                mainAxisAlignment: MainAxisAlignment.start,
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children:[
                                    Container(
                                        width: 201,
                                        height: 256,
                                        decoration: BoxDecoration(
                                            borderRadius: BorderRadius.circular(24),
                                            boxShadow: [
                                                BoxShadow(
                                                    color: Color(0x11181d31),
                                                    blurRadius: 20,
                                                    offset: Offset(25, 13),
                                                ),
                                            ],
                                        ),
                                        child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.center,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Transform.rotate(
                                                    angle: 0.20,
                                                    child: Container(
                                                        width: 327.30,
                                                        height: 245.08,
                                                        decoration: BoxDecoration(
                                                            borderRadius: BorderRadius.circular(8),
                                                            border: Border.all(color: Color(0xffbd9ac6), width: 30.30, ),
                                                            color: Color(0x7f7f3a44),
                                                        ),
                                                    ),
                                                ),
                                                SizedBox(width: 3928),
                                                Container(
                                                    width: 201,
                                                    height: 256,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(24),
                                                        color: Color(0xffe8d9ec),
                                                    ),
                                                    padding: const EdgeInsets.only(left: 16, right: 24, top: 24, bottom: 23, ),
                                                    child: Column(
                                                        mainAxisSize: MainAxisSize.min,
                                                        mainAxisAlignment: MainAxisAlignment.end,
                                                        crossAxisAlignment: CrossAxisAlignment.start,
                                                        children:[
                                                            SizedBox(
                                                                width: 105,
                                                                child: Text(
                                                                    "Debit Card",
                                                                    style: TextStyle(
                                                                        color: Color(0xff212946),
                                                                        fontSize: 16,
                                                                        fontFamily: "Poppins",
                                                                        fontWeight: FontWeight.w500,
                                                                    ),
                                                                ),
                                                            ),
                                                            SizedBox(height: 26.67),
                                                            Column(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.start,
                                                                crossAxisAlignment: CrossAxisAlignment.start,
                                                                children:[
                                                                    SizedBox(
                                                                        width: 105,
                                                                        child: Opacity(
                                                                            opacity: 0.56,
                                                                            child: Text(
                                                                                "Total Balance",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff212946),
                                                                                    fontSize: 12,
                                                                                    fontFamily: "Poppins",
                                                                                    fontWeight: FontWeight.w500,
                                                                                ),
                                                                            ),
                                                                        ),
                                                                    ),
                                                                    SizedBox(height: 8),
                                                                    Row(
                                                                        mainAxisSize: MainAxisSize.min,
                                                                        mainAxisAlignment: MainAxisAlignment.center,
                                                                        crossAxisAlignment: CrossAxisAlignment.center,
                                                                        children:[
                                                                            Text(
                                                                                "$41,000",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff212946),
                                                                                    fontSize: 26,
                                                                                    fontFamily: "Poppins",
                                                                                    fontWeight: FontWeight.w600,
                                                                                ),
                                                                            ),
                                                                            SizedBox(width: 16),
                                                                            Container(
                                                                                width: 24,
                                                                                height: 24,
                                                                                decoration: BoxDecoration(
                                                                                    borderRadius: BorderRadius.circular(8),
                                                                                ),
                                                                                child: FlutterLogo(size: 24),
                                                                            ),
                                                                        ],
                                                                    ),
                                                                ],
                                                            ),
                                                            SizedBox(height: 26.67),
                                                            Container(
                                                                width: 32,
                                                                height: 32,
                                                                decoration: BoxDecoration(
                                                                    borderRadius: BorderRadius.circular(8),
                                                                ),
                                                                child: FlutterLogo(size: 32),
                                                            ),
                                                            SizedBox(height: 26.67),
                                                            Opacity(
                                                                opacity: 0.56,
                                                                child: Text(
                                                                    "12/05",
                                                                    style: TextStyle(
                                                                        color: Color(0xff212946),
                                                                        fontSize: 14,
                                                                        fontFamily: "Poppins",
                                                                        fontWeight: FontWeight.w500,
                                                                    ),
                                                                ),
                                                            ),
                                                        ],
                                                    ),
                                                ),
                                            ],
                                        ),
                                    ),
                                    SizedBox(width: 24),
                                    Container(
                                        width: 201,
                                        height: 256,
                                        decoration: BoxDecoration(
                                            borderRadius: BorderRadius.circular(24),
                                        ),
                                        child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.center,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Transform.rotate(
                                                    angle: 0.80,
                                                    child: Container(
                                                        width: 492.46,
                                                        height: double.infinity,
                                                        decoration: BoxDecoration(
                                                            borderRadius: BorderRadius.circular(8),
                                                            border: Border.all(color: Color(0xffb26439), width: 31.46, ),
                                                            color: Color(0x7f7f3a44),
                                                        ),
                                                    ),
                                                ),
                                                SizedBox(width: 3587),
                                                Container(
                                                    width: 201,
                                                    height: 256,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(24),
                                                        color: Color(0xfffbae84),
                                                    ),
                                                    padding: const EdgeInsets.only(left: 16, right: 24, top: 16, bottom: 23, ),
                                                    child: Column(
                                                        mainAxisSize: MainAxisSize.min,
                                                        mainAxisAlignment: MainAxisAlignment.end,
                                                        crossAxisAlignment: CrossAxisAlignment.start,
                                                        children:[
                                                            Row(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.start,
                                                                crossAxisAlignment: CrossAxisAlignment.center,
                                                                children:[
                                                                    SizedBox(
                                                                        width: 105,
                                                                        child: Text(
                                                                            "Credit Card",
                                                                            style: TextStyle(
                                                                                color: Color(0xff212946),
                                                                                fontSize: 16,
                                                                                fontFamily: "Poppins",
                                                                                fontWeight: FontWeight.w500,
                                                                            ),
                                                                        ),
                                                                    ),
                                                                ],
                                                            ),
                                                            SizedBox(height: 29.33),
                                                            Column(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.start,
                                                                crossAxisAlignment: CrossAxisAlignment.start,
                                                                children:[
                                                                    SizedBox(
                                                                        width: 105,
                                                                        child: Opacity(
                                                                            opacity: 0.56,
                                                                            child: Text(
                                                                                "Total Limit",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff212946),
                                                                                    fontSize: 12,
                                                                                    fontFamily: "Poppins",
                                                                                    fontWeight: FontWeight.w500,
                                                                                ),
                                                                            ),
                                                                        ),
                                                                    ),
                                                                    SizedBox(height: 8),
                                                                    Row(
                                                                        mainAxisSize: MainAxisSize.min,
                                                                        mainAxisAlignment: MainAxisAlignment.center,
                                                                        crossAxisAlignment: CrossAxisAlignment.center,
                                                                        children:[
                                                                            Text(
                                                                                "$37,000",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff212946),
                                                                                    fontSize: 26,
                                                                                    fontFamily: "Poppins",
                                                                                    fontWeight: FontWeight.w600,
                                                                                ),
                                                                            ),
                                                                            SizedBox(width: 16),
                                                                            Container(
                                                                                width: 24,
                                                                                height: 24,
                                                                                decoration: BoxDecoration(
                                                                                    borderRadius: BorderRadius.circular(8),
                                                                                ),
                                                                                child: FlutterLogo(size: 24),
                                                                            ),
                                                                        ],
                                                                    ),
                                                                ],
                                                            ),
                                                            SizedBox(height: 29.33),
                                                            Container(
                                                                width: 32,
                                                                height: 32,
                                                                decoration: BoxDecoration(
                                                                    borderRadius: BorderRadius.circular(8),
                                                                ),
                                                                child: FlutterLogo(size: 32),
                                                            ),
                                                            SizedBox(height: 29.33),
                                                            Opacity(
                                                                opacity: 0.56,
                                                                child: Text(
                                                                    "12/05",
                                                                    style: TextStyle(
                                                                        color: Color(0xff212946),
                                                                        fontSize: 14,
                                                                        fontFamily: "Poppins",
                                                                        fontWeight: FontWeight.w500,
                                                                    ),
                                                                ),
                                                            ),
                                                        ],
                                                    ),
                                                ),
                                            ],
                                        ),
                                    ),
                                ],
                            ),
                        ),
                        SizedBox(height: 32),
                        Container(
                            width: double.infinity,
                            padding: const EdgeInsets.symmetric(horizontal: 24, ),
                            child: Column(
                                mainAxisSize: MainAxisSize.min,
                                mainAxisAlignment: MainAxisAlignment.center,
                                crossAxisAlignment: CrossAxisAlignment.center,
                                children:[
                                    Container(
                                        width: 327,
                                        child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.spaceBetween,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Text(
                                                    "Transfer",
                                                    style: TextStyle(
                                                        color: Color(0xff212946),
                                                        fontSize: 20,
                                                        fontFamily: "Poppins",
                                                        fontWeight: FontWeight.w600,
                                                    ),
                                                ),
                                                SizedBox(width: 10),
                                                Text(
                                                    "See All",
                                                    style: TextStyle(
                                                        color: Color(0xff5b6589),
                                                        fontSize: 16,
                                                        fontFamily: "Poppins",
                                                        fontWeight: FontWeight.w600,
                                                    ),
                                                ),
                                            ],
                                        ),
                                    ),
                                    SizedBox(height: 16),
                                    Container(
                                        width: 327,
                                        child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.start,
                                            crossAxisAlignment: CrossAxisAlignment.start,
                                            children:[
                                                Column(
                                                    mainAxisSize: MainAxisSize.min,
                                                    mainAxisAlignment: MainAxisAlignment.start,
                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                    children:[
                                                        Container(
                                                            width: 56,
                                                            height: 56,
                                                            child: Row(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.center,
                                                                crossAxisAlignment: CrossAxisAlignment.center,
                                                                children:[
                                                                    Container(
                                                                        width: 56,
                                                                        height: 56,
                                                                        decoration: BoxDecoration(
                                                                            borderRadius: BorderRadius.circular(44),
                                                                            color: Color(0xffbd9bc7),
                                                                        ),
                                                                        padding: const EdgeInsets.all(16),
                                                                        child: Row(
                                                                            mainAxisSize: MainAxisSize.min,
                                                                            mainAxisAlignment: MainAxisAlignment.center,
                                                                            crossAxisAlignment: CrossAxisAlignment.center,
                                                                            children:[
                                                                                Container(
                                                                                    width: 24,
                                                                                    height: 24,
                                                                                    decoration: BoxDecoration(
                                                                                        borderRadius: BorderRadius.circular(8),
                                                                                    ),
                                                                                    child: FlutterLogo(size: 24),
                                                                                ),
                                                                            ],
                                                                        ),
                                                                    ),
                                                                ],
                                                            ),
                                                        ),
                                                        SizedBox(height: 8),
                                                        SizedBox(
                                                            width: 56,
                                                            child: Text(
                                                                "Add",
                                                                textAlign: TextAlign.center,
                                                                style: TextStyle(
                                                                    color: Color(0xff212946),
                                                                    fontSize: 14,
                                                                    fontFamily: "Poppins",
                                                                    fontWeight: FontWeight.w600,
                                                                ),
                                                            ),
                                                        ),
                                                    ],
                                                ),
                                                SizedBox(width: 16),
                                                Column(
                                                    mainAxisSize: MainAxisSize.min,
                                                    mainAxisAlignment: MainAxisAlignment.start,
                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                    children:[
                                                        Container(
                                                            width: 56,
                                                            height: 56,
                                                            child: Row(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.center,
                                                                crossAxisAlignment: CrossAxisAlignment.center,
                                                                children:[
                                                                    Container(
                                                                        width: 56,
                                                                        height: 56,
                                                                        decoration: BoxDecoration(
                                                                            borderRadius: BorderRadius.circular(44),
                                                                        ),
                                                                        child: FlutterLogo(size: 56),
                                                                    ),
                                                                ],
                                                            ),
                                                        ),
                                                        SizedBox(height: 8),
                                                        SizedBox(
                                                            width: 64,
                                                            child: Text(
                                                                "Siti",
                                                                textAlign: TextAlign.center,
                                                                style: TextStyle(
                                                                    color: Color(0xff212946),
                                                                    fontSize: 14,
                                                                ),
                                                            ),
                                                        ),
                                                    ],
                                                ),
                                                SizedBox(width: 16),
                                                Column(
                                                    mainAxisSize: MainAxisSize.min,
                                                    mainAxisAlignment: MainAxisAlignment.start,
                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                    children:[
                                                        Container(
                                                            width: 56,
                                                            height: 56,
                                                            child: Row(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.center,
                                                                crossAxisAlignment: CrossAxisAlignment.center,
                                                                children:[
                                                                    Container(
                                                                        width: 56,
                                                                        height: 56,
                                                                        decoration: BoxDecoration(
                                                                            borderRadius: BorderRadius.circular(44),
                                                                        ),
                                                                        child: FlutterLogo(size: 56),
                                                                    ),
                                                                ],
                                                            ),
                                                        ),
                                                        SizedBox(height: 8),
                                                        SizedBox(
                                                            width: 64,
                                                            child: Text(
                                                                "Hamdun",
                                                                textAlign: TextAlign.center,
                                                                style: TextStyle(
                                                                    color: Color(0xff212946),
                                                                    fontSize: 14,
                                                                ),
                                                            ),
                                                        ),
                                                    ],
                                                ),
                                                SizedBox(width: 16),
                                                Column(
                                                    mainAxisSize: MainAxisSize.min,
                                                    mainAxisAlignment: MainAxisAlignment.start,
                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                    children:[
                                                        Container(
                                                            width: 56,
                                                            height: 56,
                                                            child: Row(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.center,
                                                                crossAxisAlignment: CrossAxisAlignment.center,
                                                                children:[
                                                                    Container(
                                                                        width: 56,
                                                                        height: 56,
                                                                        decoration: BoxDecoration(
                                                                            borderRadius: BorderRadius.circular(44),
                                                                        ),
                                                                        child: FlutterLogo(size: 56),
                                                                    ),
                                                                ],
                                                            ),
                                                        ),
                                                        SizedBox(height: 8),
                                                        SizedBox(
                                                            width: 64,
                                                            child: Text(
                                                                "Catlyne",
                                                                textAlign: TextAlign.center,
                                                                style: TextStyle(
                                                                    color: Color(0xff212946),
                                                                    fontSize: 14,
                                                                ),
                                                            ),
                                                        ),
                                                    ],
                                                ),
                                                SizedBox(width: 16),
                                                Column(
                                                    mainAxisSize: MainAxisSize.min,
                                                    mainAxisAlignment: MainAxisAlignment.start,
                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                    children:[
                                                        Container(
                                                            width: 56,
                                                            height: 56,
                                                            child: Row(
                                                                mainAxisSize: MainAxisSize.min,
                                                                mainAxisAlignment: MainAxisAlignment.center,
                                                                crossAxisAlignment: CrossAxisAlignment.center,
                                                                children:[
                                                                    Container(
                                                                        width: 56,
                                                                        height: 56,
                                                                        decoration: BoxDecoration(
                                                                            borderRadius: BorderRadius.circular(44),
                                                                        ),
                                                                        child: FlutterLogo(size: 56),
                                                                    ),
                                                                ],
                                                            ),
                                                        ),
                                                        SizedBox(height: 8),
                                                        SizedBox(
                                                            width: 64,
                                                            child: Text(
                                                                "Jaya",
                                                                textAlign: TextAlign.center,
                                                                style: TextStyle(
                                                                    color: Color(0xff212946),
                                                                    fontSize: 14,
                                                                ),
                                                            ),
                                                        ),
                                                    ],
                                                ),
                                            ],
                                        ),
                                    ),
                                ],
                            ),
                        ),
                        SizedBox(height: 32),
                        Container(
                            width: double.infinity,
                            padding: const EdgeInsets.symmetric(horizontal: 24, ),
                            child: Column(
                                mainAxisSize: MainAxisSize.min,
                                mainAxisAlignment: MainAxisAlignment.start,
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children:[
                                    Container(
                                        width: 327,
                                        child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.spaceBetween,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Text(
                                                    "Transactions",
                                                    style: TextStyle(
                                                        color: Color(0xff212946),
                                                        fontSize: 20,
                                                        fontFamily: "Poppins",
                                                        fontWeight: FontWeight.w600,
                                                    ),
                                                ),
                                                SizedBox(width: 10),
                                                Text(
                                                    "See All",
                                                    style: TextStyle(
                                                        color: Color(0xff5b6589),
                                                        fontSize: 16,
                                                        fontFamily: "Poppins",
                                                        fontWeight: FontWeight.w600,
                                                    ),
                                                ),
                                            ],
                                        ),
                                    ),
                                    SizedBox(height: 16),
                                    Column(
                                        mainAxisSize: MainAxisSize.min,
                                        mainAxisAlignment: MainAxisAlignment.start,
                                        crossAxisAlignment: CrossAxisAlignment.start,
                                        children:[
                                            Container(
                                                width: 327,
                                                color: Colors.white,
                                                padding: const EdgeInsets.only(bottom: 24, ),
                                                child: Row(
                                                    mainAxisSize: MainAxisSize.min,
                                                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                    children:[
                                                        Row(
                                                            mainAxisSize: MainAxisSize.min,
                                                            mainAxisAlignment: MainAxisAlignment.center,
                                                            crossAxisAlignment: CrossAxisAlignment.center,
                                                            children:[
                                                                Container(
                                                                    width: 48,
                                                                    height: 48,
                                                                    child: Row(
                                                                        mainAxisSize: MainAxisSize.min,
                                                                        mainAxisAlignment: MainAxisAlignment.center,
                                                                        crossAxisAlignment: CrossAxisAlignment.center,
                                                                        children:[
                                                                            Container(
                                                                                width: 48,
                                                                                height: 48,
                                                                                decoration: BoxDecoration(
                                                                                    borderRadius: BorderRadius.circular(36),
                                                                                    color: Color(0xffbd9bc7),
                                                                                ),
                                                                                padding: const EdgeInsets.all(12),
                                                                                child: Row(
                                                                                    mainAxisSize: MainAxisSize.min,
                                                                                    mainAxisAlignment: MainAxisAlignment.center,
                                                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                                                    children:[
                                                                                        Container(
                                                                                            width: 24,
                                                                                            height: 24,
                                                                                            decoration: BoxDecoration(
                                                                                                borderRadius: BorderRadius.circular(8),
                                                                                            ),
                                                                                            child: FlutterLogo(size: 24),
                                                                                        ),
                                                                                    ],
                                                                                ),
                                                                            ),
                                                                        ],
                                                                    ),
                                                                ),
                                                                SizedBox(width: 16),
                                                                Column(
                                                                    mainAxisSize: MainAxisSize.min,
                                                                    mainAxisAlignment: MainAxisAlignment.start,
                                                                    crossAxisAlignment: CrossAxisAlignment.start,
                                                                    children:[
                                                                        SizedBox(
                                                                            width: 182,
                                                                            child: Text(
                                                                                "Transfer to Siti",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff212946),
                                                                                    fontSize: 16,
                                                                                    fontFamily: "Poppins",
                                                                                    fontWeight: FontWeight.w600,
                                                                                ),
                                                                            ),
                                                                        ),
                                                                        SizedBox(height: 4),
                                                                        SizedBox(
                                                                            width: 182,
                                                                            child: Text(
                                                                                "Today, 08:23 PM",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff9ca2ba),
                                                                                    fontSize: 14,
                                                                                ),
                                                                            ),
                                                                        ),
                                                                    ],
                                                                ),
                                                            ],
                                                        ),
                                                        SizedBox(width: 10),
                                                        Text(
                                                            "-$326",
                                                            style: TextStyle(
                                                                color: Color(0xffef6f67),
                                                                fontSize: 16,
                                                                fontFamily: "Poppins",
                                                                fontWeight: FontWeight.w600,
                                                            ),
                                                        ),
                                                    ],
                                                ),
                                            ),
                                            SizedBox(height: 24),
                                            Container(
                                                width: 327,
                                                color: Colors.white,
                                                padding: const EdgeInsets.only(bottom: 24, ),
                                                child: Row(
                                                    mainAxisSize: MainAxisSize.min,
                                                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                    children:[
                                                        Row(
                                                            mainAxisSize: MainAxisSize.min,
                                                            mainAxisAlignment: MainAxisAlignment.center,
                                                            crossAxisAlignment: CrossAxisAlignment.center,
                                                            children:[
                                                                Container(
                                                                    width: 48,
                                                                    height: 48,
                                                                    child: Row(
                                                                        mainAxisSize: MainAxisSize.min,
                                                                        mainAxisAlignment: MainAxisAlignment.center,
                                                                        crossAxisAlignment: CrossAxisAlignment.center,
                                                                        children:[
                                                                            Container(
                                                                                width: 48,
                                                                                height: 48,
                                                                                decoration: BoxDecoration(
                                                                                    borderRadius: BorderRadius.circular(36),
                                                                                    color: Color(0xfffbae84),
                                                                                ),
                                                                                padding: const EdgeInsets.all(12),
                                                                                child: Row(
                                                                                    mainAxisSize: MainAxisSize.min,
                                                                                    mainAxisAlignment: MainAxisAlignment.center,
                                                                                    crossAxisAlignment: CrossAxisAlignment.center,
                                                                                    children:[
                                                                                        Container(
                                                                                            width: 24,
                                                                                            height: 24,
                                                                                            decoration: BoxDecoration(
                                                                                                borderRadius: BorderRadius.circular(8),
                                                                                            ),
                                                                                            child: FlutterLogo(size: 24),
                                                                                        ),
                                                                                    ],
                                                                                ),
                                                                            ),
                                                                        ],
                                                                    ),
                                                                ),
                                                                SizedBox(width: 16),
                                                                Column(
                                                                    mainAxisSize: MainAxisSize.min,
                                                                    mainAxisAlignment: MainAxisAlignment.start,
                                                                    crossAxisAlignment: CrossAxisAlignment.start,
                                                                    children:[
                                                                        SizedBox(
                                                                            width: 182,
                                                                            child: Text(
                                                                                "Coffee",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff212946),
                                                                                    fontSize: 16,
                                                                                    fontFamily: "Poppins",
                                                                                    fontWeight: FontWeight.w600,
                                                                                ),
                                                                            ),
                                                                        ),
                                                                        SizedBox(height: 4),
                                                                        SizedBox(
                                                                            width: 182,
                                                                            child: Text(
                                                                                "Yesterday, 02:51 PM",
                                                                                style: TextStyle(
                                                                                    color: Color(0xff9ca2ba),
                                                                                    fontSize: 14,
                                                                                ),
                                                                            ),
                                                                        ),
                                                                    ],
                                                                ),
                                                            ],
                                                        ),
                                                        SizedBox(width: 10),
                                                        Text(
                                                            "-$22",
                                                            style: TextStyle(
                                                                color: Color(0xffef6f67),
                                                                fontSize: 16,
                                                                fontFamily: "Poppins",
                                                                fontWeight: FontWeight.w600,
                                                            ),
                                                        ),
                                                    ],
                                                ),
                                            ),
                                        ],
                                    ),
                                ],
                            ),
                        ),
                    ],
                ),
            ),
            Positioned.fill(
                child: Align(
                    alignment: Alignment.bottomLeft,
                    child: Container(
                        width: 375,
                        height: 72,
                        color: Colors.white,
                        padding: const EdgeInsets.only(left: 44, right: 35, ),
                        child: Row(
                            mainAxisSize: MainAxisSize.min,
                            mainAxisAlignment: MainAxisAlignment.end,
                            crossAxisAlignment: CrossAxisAlignment.center,
                            children:[
                                Row(
                                    mainAxisSize: MainAxisSize.min,
                                    mainAxisAlignment: MainAxisAlignment.start,
                                    crossAxisAlignment: CrossAxisAlignment.start,
                                    children:[
                                        Column(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.start,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Container(
                                                    width: 24,
                                                    height: 24,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(8),
                                                    ),
                                                    child: FlutterLogo(size: 24),
                                                ),
                                                SizedBox(height: 4),
                                                SizedBox(
                                                    width: 56,
                                                    child: Text(
                                                        "Home",
                                                        textAlign: TextAlign.center,
                                                        style: TextStyle(
                                                            color: Color(0xff181d31),
                                                            fontSize: 12,
                                                            fontFamily: "Poppins",
                                                            fontWeight: FontWeight.w600,
                                                        ),
                                                    ),
                                                ),
                                            ],
                                        ),
                                        SizedBox(width: 24),
                                        Column(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.start,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Container(
                                                    width: 24,
                                                    height: 24,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(8),
                                                    ),
                                                    child: FlutterLogo(size: 24),
                                                ),
                                                SizedBox(height: 4),
                                                SizedBox(
                                                    width: 56,
                                                    child: Text(
                                                        "Statistics",
                                                        textAlign: TextAlign.center,
                                                        style: TextStyle(
                                                            color: Color(0xff696d80),
                                                            fontSize: 12,
                                                        ),
                                                    ),
                                                ),
                                            ],
                                        ),
                                        SizedBox(width: 24),
                                        Column(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.start,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Container(
                                                    width: 24,
                                                    height: 24,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(8),
                                                    ),
                                                    child: FlutterLogo(size: 24),
                                                ),
                                                SizedBox(height: 4),
                                                SizedBox(
                                                    width: 56,
                                                    child: Text(
                                                        "Wallet",
                                                        textAlign: TextAlign.center,
                                                        style: TextStyle(
                                                            color: Color(0xff696d80),
                                                            fontSize: 12,
                                                        ),
                                                    ),
                                                ),
                                            ],
                                        ),
                                        SizedBox(width: 24),
                                        Column(
                                            mainAxisSize: MainAxisSize.min,
                                            mainAxisAlignment: MainAxisAlignment.start,
                                            crossAxisAlignment: CrossAxisAlignment.center,
                                            children:[
                                                Container(
                                                    width: 24,
                                                    height: 24,
                                                    decoration: BoxDecoration(
                                                        borderRadius: BorderRadius.circular(8),
                                                    ),
                                                    child: FlutterLogo(size: 24),
                                                ),
                                                SizedBox(height: 4),
                                                SizedBox(
                                                    width: 56,
                                                    child: Text(
                                                        "Profile",
                                                        textAlign: TextAlign.center,
                                                        style: TextStyle(
                                                            color: Color(0xff696d80),
                                                            fontSize: 12,
                                                        ),
                                                    ),
                                                ),
                                            ],
                                        ),
                                    ],
                                ),
                            ],
                        ),
                    ),
                ),
            ),
        ],
    ),
)