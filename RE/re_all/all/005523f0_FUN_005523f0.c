
int FUN_005523f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_804;
  undefined1 local_800 [2048];
  
  if (DAT_00a834f0 == 0) {
    return -1;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar2 = FUN_005809a0(4,0,0xffffffff);
  if (iVar2 == -1) {
    return -1;
  }
  if (param_5 == 0) {
    iVar4 = FUN_005520f0(param_1,param_3,param_4);
    if (iVar4 < 0) goto LAB_005525af;
  }
  else {
    FUN_0052d510(param_2,local_800,0x800,0);
    local_804 = 0;
    FUN_0057fac0(0,&local_804,param_1,0x3c);
    FUN_0057fb10(0,&local_804,iVar2);
    FUN_0057fb30(0,&local_804,local_800);
    FUN_0057fb10(0,&local_804,param_3);
    FUN_0057fb10(0,&local_804,param_4);
    puVar3 = (undefined4 *)FUN_0057fa80(local_804);
    if (puVar3 == (undefined4 *)0x0) {
LAB_005525af:
      FUN_00580b80(iVar2);
      return -1;
    }
    puVar3[3] = &LAB_00552370;
    local_804 = 0;
    puVar1 = puVar3 + 4;
    FUN_0057fac0(puVar1,&local_804,param_1,0x3c);
    FUN_0057fb10(puVar1,&local_804,iVar2);
    FUN_0057fb30(puVar1,&local_804,local_800);
    FUN_0057fb10(puVar1,&local_804,param_3);
    FUN_0057fb10(puVar1,&local_804,param_4);
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

