class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s) > 12 or len(s) < 4:
            return []

        def isValid(ip):
            if ip.count('.') != 3:
                return False
            lst = ip.split('.')
            for num in lst:
                if not num or int(num) > 255 or (len(num) > 1 and num[0] == '0'):
                    return False
            return True

        self.res = []
        def helper(cur, idx, cnt):
            if cnt == 3:
                if isValid(cur):
                    self.res.append(cur)
                return
            if idx > len(cur) - 1:
                return
            helper(cur[:idx] + '.' + cur[idx:], idx + 2, cnt+1)
            helper(cur, idx+1, cnt)

        helper(s, 0, 0)
        return self.res

