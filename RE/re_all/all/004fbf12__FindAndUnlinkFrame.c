
/* Library Function - Single Match
    void __cdecl _FindAndUnlinkFrame(struct FrameInfo *)
   
   Library: Visual Studio 2003 Release */

void __cdecl _FindAndUnlinkFrame(FrameInfo *param_1)

{
  _ptiddata p_Var1;
  FrameInfo *pFVar2;
  
  p_Var1 = __getptd();
  if (param_1 == p_Var1->_curexception) {
    p_Var1 = __getptd();
    p_Var1->_curexception = *(void **)(param_1 + 4);
    return;
  }
  p_Var1 = __getptd();
  pFVar2 = p_Var1->_curexception;
  while( true ) {
    if (*(int *)(pFVar2 + 4) == 0) {
      _inconsistency();
      return;
    }
    if (param_1 == *(FrameInfo **)(pFVar2 + 4)) break;
    pFVar2 = *(FrameInfo **)(pFVar2 + 4);
  }
  *(undefined4 *)(pFVar2 + 4) = *(undefined4 *)(param_1 + 4);
  return;
}

