# https://leetcode.com/problems/insert-interval/
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        generatedInterval: List[List[int]] = []
            
        set_up : bool = False
        
        for interval in intervals:
            
            if not set_up and newInterval[1] < interval[0]:
                set_up = True
                generatedInterval.append(newInterval)

            temp = generatedInterval[-1] if set_up else newInterval

            
            overlap = [max(interval[0], temp[0]),
                       min(interval[1], temp[1])]
            
            
            if overlap[1] - overlap[0] < 0:
                generatedInterval.append(interval)
            else:
                merged_element = [
                    min(interval[0], temp[0]),
                    max(interval[1], temp[1])
                ]
                if set_up:
                    generatedInterval[-1] = merged_element
                else:
                    generatedInterval.append(merged_element)
                set_up = True
            
        if not set_up:
            generatedInterval.append(newInterval)
        
        return generatedInterval
        
