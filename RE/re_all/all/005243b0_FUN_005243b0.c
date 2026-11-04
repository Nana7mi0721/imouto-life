
int FUN_005243b0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,int param_7,int param_8)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_4;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar2 = FUN_005809a0(1,param_8,0xffffffff);
  if (iVar2 == -1) {
    return -1;
  }
  if ((param_7 == 0) || (param_8 != 0)) {
    iVar4 = FUN_00522dc0(param_1,iVar2,param_2,param_3,param_4 == 0,*(undefined4 *)(param_1 + 0x18),
                         param_5,param_6,0,0xffffffff,param_8);
    if (iVar4 != -1) {
      if (param_8 != 0) {
        FUN_00580f70(iVar2);
      }
      return iVar2;
    }
    if (param_8 != 0) {
      FUN_00580f70(iVar2);
    }
  }
  else {
    local_4 = 0;
    FUN_0057fac0(0,&local_4,param_1,0x6c);
    FUN_0057fb10(0,&local_4,iVar2);
    FUN_0057fb10(0,&local_4,param_2);
    FUN_0057fb10(0,&local_4,param_3);
    FUN_0057fb10(0,&local_4,param_4);
    FUN_0057fb10(0,&local_4,param_5);
    FUN_0057fb10(0,&local_4,param_6);
    FUN_0057fb10(0,&local_4,*(undefined4 *)(param_1 + 0x18));
    puVar3 = (undefined4 *)FUN_0057fa80(local_4);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[3] = FUN_005242d0;
      local_4 = 0;
      puVar1 = puVar3 + 4;
      FUN_0057fac0(puVar1,&local_4,param_1,0x6c);
      FUN_0057fb10(puVar1,&local_4,iVar2);
      FUN_0057fb10(puVar1,&local_4,param_2);
      FUN_0057fb10(puVar1,&local_4,param_3);
      FUN_0057fb10(puVar1,&local_4,param_4);
      FUN_0057fb10(puVar1,&local_4,param_5);
      FUN_0057fb10(puVar1,&local_4,param_6);
      FUN_0057fb10(puVar1,&local_4,*(undefined4 *)(param_1 + 0x18));
      iVar4 = FUN_00580290(puVar3);
      if (iVar4 < 0) {
        FUN_0056e1d0(puVar3);
        FUN_00580b80(iVar2);
        return -1;
      }
      FUN_00580610(iVar2,*puVar3);
      return iVar2;
    }
  }
  FUN_00580b80(iVar2);
  return -1;
}

