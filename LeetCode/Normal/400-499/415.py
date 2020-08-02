class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        l1=len(num1)-1
        l2=len(num2)-1
        dig=0
        res=""
        while l1>=0 and l2>=0:
            ans=(ord(num1[l1])+ord(num2[l2]))+dig-96
            res+=str(ans%10)
            dig=ans//10
            l1-=1
            l2-=1
        while l1>=0 :
            ans=ord(num1[l1])+dig-48
            res+=str(ans%10)
            dig=ans//10
            l1-=1
        while l2>=0 :
            ans=ord(num2[l2])+dig-48
            res+=str(ans%10)
            dig=ans//10
            l2-=1
        if dig>0:
            res+=str(1)
        return res[::-1]
        
