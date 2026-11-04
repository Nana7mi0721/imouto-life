
int FUN_00530090(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9,int param_10)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_4;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar2 = FUN_005809a0(8,0,param_9);
  if (iVar2 == -1) {
    return -1;
  }
  if (param_10 == 0) {
    iVar4 = FUN_0052fdc0(param_1,iVar2,param_2,param_3,param_4,param_6,param_7,param_8,0);
    if (iVar4 < 0) goto LAB_0053028b;
  }
  else {
    local_4 = 0;
    FUN_0057fac0(0,&local_4,param_1,0x14);
    FUN_0057fb10(0,&local_4,iVar2);
    FUN_0057fb30(0,&local_4,param_2);
    FUN_0057fb10(0,&local_4,param_3);
    FUN_0057fb10(0,&local_4,param_4);
    FUN_0057fb10(0,&local_4,param_5);
    FUN_0057fb10(0,&local_4,param_6);
    FUN_0057fb10(0,&local_4,param_7);
    FUN_0057fb10(0,&local_4,param_8);
    puVar3 = (undefined4 *)FUN_0057fa80(local_4);
    if (puVar3 == (undefined4 *)0x0) {
LAB_0053028b:
      FUN_00580b80(iVar2);
      return -1;
    }
    puVar3[3] = FUN_0052ffb0;
    local_4 = 0;
    puVar1 = puVar3 + 4;
    FUN_0057fac0(puVar1,&local_4,param_1,0x14);
    FUN_0057fb10(puVar1,&local_4,iVar2);
    FUN_0057fb30(puVar1,&local_4,param_2);
    FUN_0057fb10(puVar1,&local_4,param_3);
    FUN_0057fb10(puVar1,&local_4,param_4);
    FUN_0057fb10(puVar1,&local_4,param_5);
    FUN_0057fb10(puVar1,&local_4,param_6);
    FUN_0057fb10(puVar1,&local_4,param_7);
    FUN_0057fb10(puVar1,&local_4,param_8);
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

