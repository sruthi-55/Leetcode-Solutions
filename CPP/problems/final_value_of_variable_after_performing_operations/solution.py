class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        dict = {"-" : -1, "+":1}
        return sum(dict[op[1]] for op in operations)