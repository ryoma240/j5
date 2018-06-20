sign   [+-]
dot  "."
digits  [0-9]
alpha  [a-zA-Z]
white  [\n\t ]
%% 
{sign}?{digits}+    { return NUM;  }
{sign}?{digits}+{dot}{digits}*  {return RNUM; } 
{alpha}({alpha}|{digits})*  {return IDENT;}
{white}        {;}
