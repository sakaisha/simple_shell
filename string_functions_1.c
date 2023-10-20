	if (str[0] == '\n')
	{
		str[0] = '\0';
		return (count);
	}
	if (str[k] == '\n' && (str[k - 1] == ' ' || str[k - 1] == '\t') && k > 0)
	{
		str[k - 1] = '\n';
		str[k] = '\0';
	}
	return (count);
