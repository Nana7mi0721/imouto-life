
int FUN_00530620(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_4;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar2 = FUN_005809a0(8,0,param_5);
  if (iVar2 == -1) {
    return -1;
  }
  if (param_6 == 0) {
    iVar4 = FUN_005302a0(param_1,param_3,param_4,0);
    if (iVar4 < 0) goto LAB_00530788;
  }
  else {
    local_4 = 0;
    FUN_0057fac0(0,&local_4,param_1,0x14);
    FUN_0057fb10(0,&local_4,iVar2);
    FUN_0057fb10(0,&local_4,param_2);
    FUN_0057fb10(0,&local_4,param_3);
    FUN_0057fb10(0,&local_4,param_4);
    puVar3 = (undefined4 *)FUN_0057fa80(local_4);
    if (puVar3 == (undefined4 *)0x0) {
LAB_00530788:
      FUN_00580b80(iVar2);
      return -1;
    }
    puVar3[3] = &LAB_00530580;
    local_4 = 0;
    puVar1 = puVar3 + 4;
    FUN_0057fac0(puVar1,&local_4,param_1,0x14);
    FUN_0057fb10(puVar1,&local_4,iVar2);
    FUN_0057fb10(puVar1,&local_4,param_2);
    FUN_0057fb10(puVar1,&local_4,param_3);
    FUN_0057fb10(puVar1,&local_4,param_4);
    iVar4 = FUN_00580290(puVar3);
    if (iVar4 < 0) {
      FUN_0056e1d0(puVar3);
      FUN_00580b80(iVar2);
      return -1;
    }
    FUN_00580610(iVar2,*puVar3);
  }
  return iVar2;
}

