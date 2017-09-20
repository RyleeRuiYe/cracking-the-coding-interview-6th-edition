/*
 * WordFrequencies 在一本书中某个词的出现次数，如果多次运行呢
 * 思路：
 * When someone create some thing with all of their hearts, 
 * then that creature is given a soul
 */


/* 一次 助词遍历，当指定单词出现时，计数器加1；
 * 时间开销O(n)，不可能再优化，因为必须遍历书中每一个单词
 */
int getFrequency(String[] book, String word)
{
	word = word.trim().toLowerCase();
	int count = 0;
	for (String w : book)
	{
		if (w.trim().toLowerCase.equals(word))
			count++;
	}
	return count;
}

/*
  对书中单词做预处理，使用hash表把单词映射到词频
  时间开销O(1)
*/
HashMap<String, Integer> setupDictionary(String[] book)
{
	HashMap<String, Integer> table = new HashMap<String, Integer>();
	for (String word : book)
	{
		word = word.toLowerCase();
		if (word.trim() != "")
		{
			table.put(word, 0);
		}
		table.put(word, table.get(word) + 1);
	}
	return table;
}

int getFrequency(HashMap<String, Integer> table, String word)
{
	if (table == NULL || word == NULL)
		return -1;
	word = word.toLowerCase();
	if (table.containsKey(word))
		return table.get(word);
	return 0;
}
