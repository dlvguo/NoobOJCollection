class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 根据输入的面值faceValue，年利率couponRate，折现率discountRate，年期n，计算出这个债券的估值bookValue。
计算结果与正确答案差值在0.0001以内算为正确。
     * @param faceValue double浮点型 大于0，小于1000000
     * @param couponRate double浮点型 大于0，小于50，实际计算的时候注意需要换成%数
     * @param discountRate double浮点型 大于0，小于50，实际计算的时候注意需要换成%数
     * @param n int整型 年数，大于0，小于50
     * @return double浮点型
     */
    double getBookValue(double faceValue, double couponRate, double discountRate, int n)
    {
        couponRate /= 100;
        discountRate /= 100;
        double res = 0, xj = faceValue * couponRate;
        discountRate += 1;
        double oriDis = discountRate;
        while (n--)
        {
            res += xj / discountRate;
            if (!n)
                res += faceValue / discountRate;
            discountRate *= oriDis;
        }

        return res;
    }
};