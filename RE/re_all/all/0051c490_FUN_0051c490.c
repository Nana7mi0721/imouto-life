
int FUN_0051c490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar2 = FUN_00567b30();
  if ((iVar2 == 0) || (DAT_00a37dc8 == 0)) {
    return -1;
  }
  if (DAT_00a37d70 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = FUN_005809a0(0xc,param_6,0xffffffff);
    if (iVar2 != -1) {
      if ((param_5 != 0) && (param_6 == 0)) {
        local_4 = 0;
        FUN_0057fb10(0,&local_4,iVar2);
        FUN_0057fb10(0,&local_4,param_1);
        FUN_0057fb10(0,&local_4,param_2);
        FUN_0057fb10(0,&local_4,param_3);
        FUN_0057fb10(0,&local_4,param_4);
        puVar3 = (undefined4 *)FUN_0057fa80(local_4);
        if (puVar3 != (undefined4 *)0x0) {
          puVar3[3] = &LAB_0051c400;
          local_4 = 0;
          puVar1 = puVar3 + 4;
          FUN_0057fb10(puVar1,&local_4,iVar2);
          FUN_0057fb10(puVar1,&local_4,param_1);
          FUN_0057fb10(puVar1,&local_4,param_2);
          FUN_0057fb10(puVar1,&local_4,param_3);
          FUN_0057fb10(puVar1,&local_4,param_4);
          iVar4 = FUN_00580290(puVar3);
          if (-1 < iVar4) {
            FUN_00580610(iVar2,*puVar3);
            return iVar2;
          }
          FUN_0056e1d0(puVar3);
        }
        goto LAB_0051c603;
      }
      iVar4 = FUN_00568c20(iVar2,param_1,param_2,param_3,param_4,param_6);
      if (-1 < iVar4) {
        if (param_6 != 0) {
          FUN_00580f70(iVar2);
        }
        return iVar2;
      }
    }
  }
  if (param_6 != 0) {
    FUN_00580f70(iVar2);
  }
LAB_0051c603:
  FUN_00580b80(iVar2);
  return -1;
}

