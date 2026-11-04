
/* Library Function - Single Match
    __getptd
   
   Library: Visual Studio 2003 Release */

_ptiddata __cdecl __getptd(void)

{
  DWORD dwErrCode;
  _ptiddata p_Var1;
  int iVar2;
  DWORD DVar3;
  
  dwErrCode = GetLastError();
  p_Var1 = (_ptiddata)(*DAT_00a1fc48)(DAT_0084b6ec);
  if (p_Var1 == (_ptiddata)0x0) {
    p_Var1 = _calloc(1,0x8c);
    if (p_Var1 != (_ptiddata)0x0) {
      iVar2 = (*DAT_00a1fc4c)(DAT_0084b6ec,p_Var1);
      if (iVar2 != 0) {
        p_Var1->_initaddr = &DAT_0084c010;
        p_Var1->_holdrand = 1;
        DVar3 = GetCurrentThreadId();
        p_Var1->_thandle = 0xffffffff;
        p_Var1->_tid = DVar3;
        goto LAB_005008a8;
      }
    }
    __amsg_exit(0x10);
  }
LAB_005008a8:
  SetLastError(dwErrCode);
  return p_Var1;
}

