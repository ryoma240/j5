sign   [+-]
dot  "."
digits  [0-9]
alpha  [a-zA-Z]
index  [e]
white  [\n\t ]
%% 
{sign}?{digits}+    { return NUM;  }
{sign}?{digits}+{dot}{digits}*  {return RNUM; } 
{sign}?{digits}+{index}{sign}?{digits}+  {return INDEX; }
{sign}?{digits}+{dot}{digits}*{index}{sign}?{digits}+  {return INDEX; }
{alpha}({alpha}|{digits})*  {return IDENT;}
{white}        {;}
