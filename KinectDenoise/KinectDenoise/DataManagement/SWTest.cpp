#include "SWTest.h"


// for sort
bool cmp(const Vertex& a, const Vertex& b)
{
	return a.z > b.z;
}

void SWTest::setPValue()
{
	/// 0.05
	/*m_PValue[3] = 0.767, m_PValue[4] = 0.748, m_PValue[5] = 0.762, m_PValue[6] = 0.788, m_PValue[7] = 0.803, m_PValue[8] = 0.818;
	m_PValue[9] = 0.829, m_PValue[10] = 0.842, m_PValue[11] = 0.850, m_PValue[12] = 0.859, m_PValue[13] = 0.866, m_PValue[14] = 0.874;
	m_PValue[15] = 0.881, m_PValue[16] = 0.887, m_PValue[17] = 0.892, m_PValue[18] = 0.897, m_PValue[19] = 0.901, m_PValue[20] = 0.905;
	m_PValue[21] = 0.908, m_PValue[22] = 0.911, m_PValue[23] = 0.914, m_PValue[24] = 0.916, m_PValue[25] = 0.918, m_PValue[26] = 0.920;
	m_PValue[27] = 0.923, m_PValue[28] = 0.924, m_PValue[29] = 0.926, m_PValue[30] = 0.927, m_PValue[31] = 0.929, m_PValue[32] = 0.930;
	m_PValue[33] = 0.931, m_PValue[34] = 0.933, m_PValue[35] = 0.934, m_PValue[36] = 0.935, m_PValue[37] = 0.936, m_PValue[38] = 0.938;
	m_PValue[39] = 0.939, m_PValue[40] = 0.940, m_PValue[41] = 0.941, m_PValue[42] = 0.942, m_PValue[43] = 0.943, m_PValue[44] = 0.944;
	m_PValue[45] = 0.945, m_PValue[46] = 0.946, m_PValue[47] = 0.947, m_PValue[48] = 0.947, m_PValue[49] = 0.947, m_PValue[50] = 0.947;*/

	/// 0.01
	m_PValue[3] = 0.753, m_PValue[4] = 0.687, m_PValue[5] = 0.686, m_PValue[6] = 0.713, m_PValue[7] = 0.730, m_PValue[8] = 0.749;
	m_PValue[9] = 0.764, m_PValue[10] = 0.781, m_PValue[11] = 0.792, m_PValue[12] = 0.805, m_PValue[13] = 0.814, m_PValue[14] = 0.825;
	m_PValue[15] = 0.835, m_PValue[16] = 0.844, m_PValue[17] = 0.851, m_PValue[18] = 0.858, m_PValue[19] = 0.863, m_PValue[20] = 0.868;
	m_PValue[21] = 0.873, m_PValue[22] = 0.878, m_PValue[23] = 0.881, m_PValue[24] = 0.884, m_PValue[25] = 0.888, m_PValue[26] = 0.891;
	m_PValue[27] = 0.894, m_PValue[28] = 0.896, m_PValue[29] = 0.898, m_PValue[30] = 0.900, m_PValue[31] = 0.902, m_PValue[32] = 0.904;
	m_PValue[33] = 0.906, m_PValue[34] = 0.908, m_PValue[35] = 0.910, m_PValue[36] = 0.912, m_PValue[37] = 0.914, m_PValue[38] = 0.916;
	m_PValue[39] = 0.917, m_PValue[40] = 0.919, m_PValue[41] = 0.920, m_PValue[42] = 0.922, m_PValue[43] = 0.923, m_PValue[44] = 0.924;
	m_PValue[45] = 0.926, m_PValue[46] = 0.927, m_PValue[47] = 0.928, m_PValue[48] = 0.929, m_PValue[49] = 0.929, m_PValue[50] = 0.930;

}

void SWTest::setPValue(map<int, float> pvalue)
{
	this->m_PValue = pvalue;
}

void SWTest::setShapiroWilkTable()
{
	vector<float> tempTable;

	tempTable.push_back(0.7071);
	m_ShapiroWilkTable[2] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.7071);
	m_ShapiroWilkTable[3] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.6872), tempTable.push_back(0.1677);
	m_ShapiroWilkTable[4] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.6645), tempTable.push_back(0.2413);
	m_ShapiroWilkTable[5] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.6431), tempTable.push_back(0.2805), tempTable.push_back(0.0875);
	m_ShapiroWilkTable[6] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.6233), tempTable.push_back(0.3031), tempTable.push_back(0.1401);
	m_ShapiroWilkTable[7] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.6052), tempTable.push_back(0.3164), tempTable.push_back(0.1743), tempTable.push_back(0.0561);
	m_ShapiroWilkTable[8] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5888), tempTable.push_back(0.3244), tempTable.push_back(0.1976), tempTable.push_back(0.0947);
	m_ShapiroWilkTable[9] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5739), tempTable.push_back(0.3291), tempTable.push_back(0.2141), tempTable.push_back(0.1224), tempTable.push_back(0.0399);
	m_ShapiroWilkTable[10] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5601), tempTable.push_back(0.3315), tempTable.push_back(0.2260), tempTable.push_back(0.1429), tempTable.push_back(0.0695);
	m_ShapiroWilkTable[11] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5475), tempTable.push_back(0.3325), tempTable.push_back(0.2347), tempTable.push_back(0.1586), tempTable.push_back(0.0922);
	tempTable.push_back(0.0303);
	m_ShapiroWilkTable[12] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5359), tempTable.push_back(0.3325), tempTable.push_back(0.2412), tempTable.push_back(0.1707), tempTable.push_back(0.1099);
	tempTable.push_back(0.0539);
	m_ShapiroWilkTable[13] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5251), tempTable.push_back(0.3318), tempTable.push_back(0.2460), tempTable.push_back(0.1802), tempTable.push_back(0.1240);
	tempTable.push_back(0.0727), tempTable.push_back(0.0240);
	m_ShapiroWilkTable[14] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5150), tempTable.push_back(0.3306), tempTable.push_back(0.2495), tempTable.push_back(0.1878), tempTable.push_back(0.1353);
	tempTable.push_back(0.0880), tempTable.push_back(0.0433);
	m_ShapiroWilkTable[15] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.5056), tempTable.push_back(0.3290), tempTable.push_back(0.2521), tempTable.push_back(0.1939), tempTable.push_back(0.1447);
	tempTable.push_back(0.1005), tempTable.push_back(0.0593), tempTable.push_back(0.0196);
	m_ShapiroWilkTable[16] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4968), tempTable.push_back(0.3273), tempTable.push_back(0.2540), tempTable.push_back(0.1988), tempTable.push_back(0.1524);
	tempTable.push_back(0.1109), tempTable.push_back(0.0725), tempTable.push_back(0.0359);
	m_ShapiroWilkTable[17] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4886), tempTable.push_back(0.3253), tempTable.push_back(0.2553), tempTable.push_back(0.2027), tempTable.push_back(0.1587);
	tempTable.push_back(0.1197), tempTable.push_back(0.0837), tempTable.push_back(0.0496), tempTable.push_back(0.0163);
	m_ShapiroWilkTable[18] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4808), tempTable.push_back(0.3232), tempTable.push_back(0.2561), tempTable.push_back(0.2059), tempTable.push_back(0.1641);
	tempTable.push_back(0.1271), tempTable.push_back(0.0932), tempTable.push_back(0.0612), tempTable.push_back(0.0303);
	m_ShapiroWilkTable[19] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4734), tempTable.push_back(0.3211), tempTable.push_back(0.2565), tempTable.push_back(0.2085), tempTable.push_back(0.1686);
	tempTable.push_back(0.1334), tempTable.push_back(0.1013), tempTable.push_back(0.0711), tempTable.push_back(0.0422), tempTable.push_back(0.0140);
	m_ShapiroWilkTable[20] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4643), tempTable.push_back(0.3185), tempTable.push_back(0.2578), tempTable.push_back(0.2119), tempTable.push_back(0.1736);
	tempTable.push_back(0.1399), tempTable.push_back(0.1092), tempTable.push_back(0.0804), tempTable.push_back(0.0530), tempTable.push_back(0.0263);
	m_ShapiroWilkTable[21] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4590), tempTable.push_back(0.3156), tempTable.push_back(0.2571), tempTable.push_back(0.2131), tempTable.push_back(0.1764);
	tempTable.push_back(0.1443), tempTable.push_back(0.1150), tempTable.push_back(0.0878), tempTable.push_back(0.0618), tempTable.push_back(0.0368);
	tempTable.push_back(0.0122);
	m_ShapiroWilkTable[22] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4542), tempTable.push_back(0.3126), tempTable.push_back(0.2563), tempTable.push_back(0.2139), tempTable.push_back(0.1787);
	tempTable.push_back(0.1480), tempTable.push_back(0.1201), tempTable.push_back(0.0941), tempTable.push_back(0.0696), tempTable.push_back(0.0459);
	tempTable.push_back(0.0228);
	m_ShapiroWilkTable[23] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4493), tempTable.push_back(0.3098), tempTable.push_back(0.2554), tempTable.push_back(0.2145), tempTable.push_back(0.1807);
	tempTable.push_back(0.1512), tempTable.push_back(0.1245), tempTable.push_back(0.0997), tempTable.push_back(0.0764), tempTable.push_back(0.0539);
	tempTable.push_back(0.0321), tempTable.push_back(0.0107);
	m_ShapiroWilkTable[24] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4450), tempTable.push_back(0.3069), tempTable.push_back(0.2543), tempTable.push_back(0.2148), tempTable.push_back(0.1822);
	tempTable.push_back(0.1539), tempTable.push_back(0.1283), tempTable.push_back(0.1046), tempTable.push_back(0.0823), tempTable.push_back(0.0610);
	tempTable.push_back(0.0403), tempTable.push_back(0.02);
	m_ShapiroWilkTable[25] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4407), tempTable.push_back(0.3043), tempTable.push_back(0.2533), tempTable.push_back(0.2151), tempTable.push_back(0.1836);
	tempTable.push_back(0.1563), tempTable.push_back(0.1316), tempTable.push_back(0.1089), tempTable.push_back(0.0876), tempTable.push_back(0.0672);
	tempTable.push_back(0.0476), tempTable.push_back(0.0284), tempTable.push_back(0.0094);
	m_ShapiroWilkTable[26] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4366), tempTable.push_back(0.3018), tempTable.push_back(0.2522), tempTable.push_back(0.2152), tempTable.push_back(0.1848);
	tempTable.push_back(0.1584), tempTable.push_back(0.1346), tempTable.push_back(0.1128), tempTable.push_back(0.0923), tempTable.push_back(0.0728);
	tempTable.push_back(0.0540), tempTable.push_back(0.0358), tempTable.push_back(0.0178);
	m_ShapiroWilkTable[27] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4328), tempTable.push_back(0.2992), tempTable.push_back(0.2510), tempTable.push_back(0.2151), tempTable.push_back(0.1857);
	tempTable.push_back(0.1601), tempTable.push_back(0.1372), tempTable.push_back(0.1162), tempTable.push_back(0.0965), tempTable.push_back(0.0778);
	tempTable.push_back(0.0598), tempTable.push_back(0.0424), tempTable.push_back(0.0253), tempTable.push_back(0.0084);
	m_ShapiroWilkTable[28] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4291), tempTable.push_back(0.2968), tempTable.push_back(0.2499), tempTable.push_back(0.2150), tempTable.push_back(0.1864);
	tempTable.push_back(0.1616), tempTable.push_back(0.1395), tempTable.push_back(0.1192), tempTable.push_back(0.1002), tempTable.push_back(0.0822);
	tempTable.push_back(0.0650), tempTable.push_back(0.0483), tempTable.push_back(0.0320), tempTable.push_back(0.0159);
	m_ShapiroWilkTable[29] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4254), tempTable.push_back(0.2944), tempTable.push_back(0.2487), tempTable.push_back(0.2148), tempTable.push_back(0.1870);
	tempTable.push_back(0.1630), tempTable.push_back(0.1415), tempTable.push_back(0.1219), tempTable.push_back(0.1036), tempTable.push_back(0.0862);
	tempTable.push_back(0.0697), tempTable.push_back(0.0537), tempTable.push_back(0.0381), tempTable.push_back(0.0227), tempTable.push_back(0.0076);
	m_ShapiroWilkTable[30] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4220), tempTable.push_back(0.2921), tempTable.push_back(0.2475), tempTable.push_back(0.2145), tempTable.push_back(0.1874);
	tempTable.push_back(0.1641), tempTable.push_back(0.1433), tempTable.push_back(0.1243), tempTable.push_back(0.1066), tempTable.push_back(0.0899);
	tempTable.push_back(0.0739), tempTable.push_back(0.0585), tempTable.push_back(0.0435), tempTable.push_back(0.0289), tempTable.push_back(0.0144);
	m_ShapiroWilkTable[31] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4188), tempTable.push_back(0.2898), tempTable.push_back(0.2463), tempTable.push_back(0.2141), tempTable.push_back(0.1878);
	tempTable.push_back(0.1651), tempTable.push_back(0.1449), tempTable.push_back(0.1265), tempTable.push_back(0.1093), tempTable.push_back(0.0931);
	tempTable.push_back(0.0777), tempTable.push_back(0.0629), tempTable.push_back(0.0485), tempTable.push_back(0.0344), tempTable.push_back(0.0206);
	tempTable.push_back(0.0068);
	m_ShapiroWilkTable[32] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4156), tempTable.push_back(0.2876), tempTable.push_back(0.2451), tempTable.push_back(0.2137), tempTable.push_back(0.1880);
	tempTable.push_back(0.1660), tempTable.push_back(0.1463), tempTable.push_back(0.1284), tempTable.push_back(0.1118), tempTable.push_back(0.0961);
	tempTable.push_back(0.0812), tempTable.push_back(0.0669), tempTable.push_back(0.0530), tempTable.push_back(0.0395), tempTable.push_back(0.0262);
	tempTable.push_back(0.0131);
	m_ShapiroWilkTable[33] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4127), tempTable.push_back(0.2854), tempTable.push_back(0.2439), tempTable.push_back(0.2132), tempTable.push_back(0.1882);
	tempTable.push_back(0.1667), tempTable.push_back(0.1475), tempTable.push_back(0.1301), tempTable.push_back(0.1140), tempTable.push_back(0.0988);
	tempTable.push_back(0.0844), tempTable.push_back(0.0706), tempTable.push_back(0.0572), tempTable.push_back(0.0441), tempTable.push_back(0.0314);
	tempTable.push_back(0.0187), tempTable.push_back(0.0062);
	m_ShapiroWilkTable[34] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4096), tempTable.push_back(0.2834), tempTable.push_back(0.2427), tempTable.push_back(0.2127), tempTable.push_back(0.1883);
	tempTable.push_back(0.1673), tempTable.push_back(0.1487), tempTable.push_back(0.1317), tempTable.push_back(0.1160), tempTable.push_back(0.1013);
	tempTable.push_back(0.0873), tempTable.push_back(0.0739), tempTable.push_back(0.0610), tempTable.push_back(0.0484), tempTable.push_back(0.0361);
	tempTable.push_back(0.0239), tempTable.push_back(0.0119);
	m_ShapiroWilkTable[35] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4068), tempTable.push_back(0.2813), tempTable.push_back(0.2415), tempTable.push_back(0.2121), tempTable.push_back(0.1883);
	tempTable.push_back(0.1678), tempTable.push_back(0.1496), tempTable.push_back(0.1331), tempTable.push_back(0.1179), tempTable.push_back(0.1036);
	tempTable.push_back(0.0900), tempTable.push_back(0.0770), tempTable.push_back(0.0645), tempTable.push_back(0.0523), tempTable.push_back(0.0404);
	tempTable.push_back(0.0287), tempTable.push_back(0.0172), tempTable.push_back(0.0057);
	m_ShapiroWilkTable[36] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4040), tempTable.push_back(0.2794), tempTable.push_back(0.2403), tempTable.push_back(0.2116), tempTable.push_back(0.1883);
	tempTable.push_back(0.1683), tempTable.push_back(0.1505), tempTable.push_back(0.1344), tempTable.push_back(0.1196), tempTable.push_back(0.1056);
	tempTable.push_back(0.0924), tempTable.push_back(0.0798), tempTable.push_back(0.0677), tempTable.push_back(0.0559), tempTable.push_back(0.0444);
	tempTable.push_back(0.0331), tempTable.push_back(0.0220), tempTable.push_back(0.0110);
	m_ShapiroWilkTable[37] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.4015), tempTable.push_back(0.2774), tempTable.push_back(0.2391), tempTable.push_back(0.2110), tempTable.push_back(0.1881);
	tempTable.push_back(0.1686), tempTable.push_back(0.1513), tempTable.push_back(0.1356), tempTable.push_back(0.1211), tempTable.push_back(0.1075);
	tempTable.push_back(0.0947), tempTable.push_back(0.0824), tempTable.push_back(0.0706), tempTable.push_back(0.0592), tempTable.push_back(0.0481);
	tempTable.push_back(0.0372), tempTable.push_back(0.0264), tempTable.push_back(0.0158), tempTable.push_back(0.0053);
	m_ShapiroWilkTable[38] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3989), tempTable.push_back(0.2755), tempTable.push_back(0.2380), tempTable.push_back(0.2104), tempTable.push_back(0.1880);
	tempTable.push_back(0.1689), tempTable.push_back(0.1520), tempTable.push_back(0.1366), tempTable.push_back(0.1225), tempTable.push_back(0.1092);
	tempTable.push_back(0.0967), tempTable.push_back(0.0848), tempTable.push_back(0.0733), tempTable.push_back(0.0622), tempTable.push_back(0.0515);
	tempTable.push_back(0.0409), tempTable.push_back(0.0305), tempTable.push_back(0.0203), tempTable.push_back(0.0101);
	m_ShapiroWilkTable[39] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3964), tempTable.push_back(0.2737), tempTable.push_back(0.2368), tempTable.push_back(0.2098), tempTable.push_back(0.1878);
	tempTable.push_back(0.1691), tempTable.push_back(0.1526), tempTable.push_back(0.1376), tempTable.push_back(0.1237), tempTable.push_back(0.1108);
	tempTable.push_back(0.0986), tempTable.push_back(0.0870), tempTable.push_back(0.0759), tempTable.push_back(0.0651), tempTable.push_back(0.0546);
	tempTable.push_back(0.0444), tempTable.push_back(0.0343), tempTable.push_back(0.0244), tempTable.push_back(0.0146), tempTable.push_back(0.0049);
	m_ShapiroWilkTable[40] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3940), tempTable.push_back(0.2719), tempTable.push_back(0.2357), tempTable.push_back(0.2091), tempTable.push_back(0.1876);
	tempTable.push_back(0.1693), tempTable.push_back(0.1531), tempTable.push_back(0.1384), tempTable.push_back(0.1249), tempTable.push_back(0.1123);
	tempTable.push_back(0.1004), tempTable.push_back(0.0891), tempTable.push_back(0.0782), tempTable.push_back(0.0677), tempTable.push_back(0.0575);
	tempTable.push_back(0.0476), tempTable.push_back(0.0379), tempTable.push_back(0.0283), tempTable.push_back(0.0188), tempTable.push_back(0.0094);
	m_ShapiroWilkTable[41] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3917), tempTable.push_back(0.2701), tempTable.push_back(0.2345), tempTable.push_back(0.2085), tempTable.push_back(0.1874);
	tempTable.push_back(0.1694), tempTable.push_back(0.1535), tempTable.push_back(0.1392), tempTable.push_back(0.1259), tempTable.push_back(0.1136);
	tempTable.push_back(0.1020), tempTable.push_back(0.0909), tempTable.push_back(0.0804), tempTable.push_back(0.0701), tempTable.push_back(0.0602);
	tempTable.push_back(0.0506), tempTable.push_back(0.0411), tempTable.push_back(0.0318), tempTable.push_back(0.0227), tempTable.push_back(0.0136);
	tempTable.push_back(0.0045);
	m_ShapiroWilkTable[42] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3894), tempTable.push_back(0.2684), tempTable.push_back(0.2334), tempTable.push_back(0.2078), tempTable.push_back(0.1871);
	tempTable.push_back(0.1695), tempTable.push_back(0.1539), tempTable.push_back(0.1398), tempTable.push_back(0.1269), tempTable.push_back(0.1149);
	tempTable.push_back(0.1035), tempTable.push_back(0.0927), tempTable.push_back(0.0824), tempTable.push_back(0.0724), tempTable.push_back(0.0628);
	tempTable.push_back(0.0534), tempTable.push_back(0.0442), tempTable.push_back(0.0352), tempTable.push_back(0.0263), tempTable.push_back(0.0175);
	tempTable.push_back(0.0087);
	m_ShapiroWilkTable[43] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3872), tempTable.push_back(0.2667), tempTable.push_back(0.2323), tempTable.push_back(0.2072), tempTable.push_back(0.1868);
	tempTable.push_back(0.1695), tempTable.push_back(0.1542), tempTable.push_back(0.1405), tempTable.push_back(0.1278), tempTable.push_back(0.1160);
	tempTable.push_back(0.1049), tempTable.push_back(0.0943), tempTable.push_back(0.0842), tempTable.push_back(0.0745), tempTable.push_back(0.0651);
	tempTable.push_back(0.0560), tempTable.push_back(0.0471), tempTable.push_back(0.0383), tempTable.push_back(0.0296), tempTable.push_back(0.0211);
	tempTable.push_back(0.0126), tempTable.push_back(0.0042);
	m_ShapiroWilkTable[44] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3850), tempTable.push_back(0.2651), tempTable.push_back(0.2313), tempTable.push_back(0.2065), tempTable.push_back(0.1865);
	tempTable.push_back(0.1695), tempTable.push_back(0.1545), tempTable.push_back(0.1410), tempTable.push_back(0.1286), tempTable.push_back(0.1170);
	tempTable.push_back(0.1062), tempTable.push_back(0.0959), tempTable.push_back(0.0860), tempTable.push_back(0.0765), tempTable.push_back(0.0673);
	tempTable.push_back(0.0584), tempTable.push_back(0.0497), tempTable.push_back(0.0412), tempTable.push_back(0.0328), tempTable.push_back(0.0245);
	tempTable.push_back(0.0163), tempTable.push_back(0.0081);
	m_ShapiroWilkTable[45] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3830), tempTable.push_back(0.2635), tempTable.push_back(0.2302), tempTable.push_back(0.2058), tempTable.push_back(0.1862);
	tempTable.push_back(0.1695), tempTable.push_back(0.1548), tempTable.push_back(0.1410), tempTable.push_back(0.1286), tempTable.push_back(0.1170);
	tempTable.push_back(0.1062), tempTable.push_back(0.0972), tempTable.push_back(0.0876), tempTable.push_back(0.0783), tempTable.push_back(0.0694);
	tempTable.push_back(0.0607), tempTable.push_back(0.0522), tempTable.push_back(0.0439), tempTable.push_back(0.0357), tempTable.push_back(0.0277);
	tempTable.push_back(0.0197), tempTable.push_back(0.0118), tempTable.push_back(0.0039);
	m_ShapiroWilkTable[46] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3808), tempTable.push_back(0.2620), tempTable.push_back(0.2291), tempTable.push_back(0.2052), tempTable.push_back(0.1859);
	tempTable.push_back(0.1695), tempTable.push_back(0.1550), tempTable.push_back(0.1420), tempTable.push_back(0.1300), tempTable.push_back(0.1189);
	tempTable.push_back(0.1085), tempTable.push_back(0.0986), tempTable.push_back(0.0892), tempTable.push_back(0.0801), tempTable.push_back(0.0713);
	tempTable.push_back(0.0628), tempTable.push_back(0.0546), tempTable.push_back(0.0465), tempTable.push_back(0.0385), tempTable.push_back(0.0307);
	tempTable.push_back(0.0229), tempTable.push_back(0.0153), tempTable.push_back(0.0076);
	m_ShapiroWilkTable[47] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3789), tempTable.push_back(0.2604), tempTable.push_back(0.2281), tempTable.push_back(0.2045), tempTable.push_back(0.1855);
	tempTable.push_back(0.1693), tempTable.push_back(0.1551), tempTable.push_back(0.1423), tempTable.push_back(0.1306), tempTable.push_back(0.1197);
	tempTable.push_back(0.1095), tempTable.push_back(0.0998), tempTable.push_back(0.0906), tempTable.push_back(0.0817), tempTable.push_back(0.0731);
	tempTable.push_back(0.0648), tempTable.push_back(0.0568), tempTable.push_back(0.0489), tempTable.push_back(0.0411), tempTable.push_back(0.0335);
	tempTable.push_back(0.0259), tempTable.push_back(0.0185), tempTable.push_back(0.0111), tempTable.push_back(0.0037);
	m_ShapiroWilkTable[48] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3770), tempTable.push_back(0.2589), tempTable.push_back(0.2271), tempTable.push_back(0.2038), tempTable.push_back(0.1851);
	tempTable.push_back(0.1692), tempTable.push_back(0.1553), tempTable.push_back(0.1427), tempTable.push_back(0.1312), tempTable.push_back(0.1205);
	tempTable.push_back(0.1105), tempTable.push_back(0.1010), tempTable.push_back(0.0919), tempTable.push_back(0.0832), tempTable.push_back(0.0748);
	tempTable.push_back(0.0667), tempTable.push_back(0.0588), tempTable.push_back(0.0511), tempTable.push_back(0.0436), tempTable.push_back(0.0361);
	tempTable.push_back(0.0288), tempTable.push_back(0.0215), tempTable.push_back(0.0143), tempTable.push_back(0.0071);
	m_ShapiroWilkTable[49] = tempTable;
	tempTable.clear();

	tempTable.push_back(0.3751), tempTable.push_back(0.2574), tempTable.push_back(0.2260), tempTable.push_back(0.2032), tempTable.push_back(0.1847);
	tempTable.push_back(0.1691), tempTable.push_back(0.1554), tempTable.push_back(0.1430), tempTable.push_back(0.1317), tempTable.push_back(0.1212);
	tempTable.push_back(0.1113), tempTable.push_back(0.1020), tempTable.push_back(0.0932), tempTable.push_back(0.0846), tempTable.push_back(0.0764);
	tempTable.push_back(0.0685), tempTable.push_back(0.0608), tempTable.push_back(0.0532), tempTable.push_back(0.0459), tempTable.push_back(0.0386);
	tempTable.push_back(0.0314), tempTable.push_back(0.0244), tempTable.push_back(0.0174), tempTable.push_back(0.0104), tempTable.push_back(0.0035);
	m_ShapiroWilkTable[50] = tempTable;
	tempTable.clear();
}

void SWTest::setShapiroWilkTable(map<int, vector<float>> shapirowilk)
{
	this->m_ShapiroWilkTable = shapirowilk;
}

bool SWTest::ShapiroWilkTest(vector<Vertex> storage)
{
	sort(storage.begin(), storage.end(), cmp);

	int num = storage.size();

	vector<float> table = this->m_ShapiroWilkTable[num];
	float score = this->m_PValue[num];

	int counter = 0, end_ = num - 1;
	float b = 0;
	for (register int i = 0; i < end_; i++)
	{
		float head = storage[i].z, tail = storage[end_--].z;
		b += (tail - head) * table[counter++];
	}

	float mean = 0;
	for (register int i = 0; i < num; i++)
	{
		mean += storage[i].z;
	}
	mean /= num;

	float ss = 0;
	for (register int i = 0; i < num; i++)
	{
		ss += pow(storage[i].z - mean, 2);
	}

	float w = pow(b, 2) / ss;

	if (w >= score)
		return true; /// normal
	else
		return false; /// not - normal
}
