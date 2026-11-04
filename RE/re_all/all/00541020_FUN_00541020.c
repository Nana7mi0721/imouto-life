
undefined4 FUN_00541020(int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar1 = param_2;
  local_4 = -1;
  iVar4 = 0;
  while( true ) {
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar2 = FUN_00572fc0(iVar4 + param_1,DAT_00aba250,&param_2);
    if (iVar2 == 0) break;
    if (iVar2 == 0x2e) {
      local_4 = iVar4;
    }
    iVar4 = iVar4 + param_2;
  }
  iVar4 = 0;
  while( true ) {
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar2 = FUN_00572fc0(iVar4 + param_1,DAT_00aba250,&param_2);
    if ((iVar2 == 0) || (iVar4 == local_4)) break;
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    thunk_FUN_00573310(iVar2,DAT_00aba250,iVar4 + iVar1,in_EAX - iVar4);
    iVar4 = iVar4 + param_2;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar2 = thunk_FUN_00573310(0x5f,DAT_00aba250,iVar4 + iVar1,in_EAX - iVar4);
  iVar2 = iVar2 + iVar4;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar3 = thunk_FUN_00573310(0x61,DAT_00aba250,iVar2 + iVar1,in_EAX - iVar2);
  FUN_0056cf70(iVar2 + iVar3 + iVar1,in_EAX - (iVar2 + iVar3),iVar4 + param_1);
  return 0;
}

