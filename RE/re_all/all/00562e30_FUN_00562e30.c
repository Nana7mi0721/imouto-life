
uint FUN_00562e30(undefined4 *param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6,undefined4 param_7,int param_8,int param_9)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_4;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    if (param_9 != 0) {
      FUN_00580610(param_3,0xffffffff);
    }
LAB_00562e84:
    if ((param_8 != 0) && (param_9 == 0)) {
      local_4 = param_9;
      FUN_0057fac0(0,&local_4,param_1,0x3c);
      FUN_0057fb10(0,&local_4,param_2);
      FUN_0057fb10(0,&local_4,param_3);
      FUN_0057fb10(0,&local_4,param_4);
      FUN_0057fb10(0,&local_4,param_5);
      FUN_0057fb10(0,&local_4,param_6);
      FUN_0057fb10(0,&local_4,param_7);
      puVar3 = (undefined4 *)FUN_0057fa80(local_4);
      if (puVar3 != (undefined4 *)0x0) {
        puVar1 = puVar3 + 4;
        puVar3[3] = FUN_00562d70;
        local_4 = 0;
        FUN_0057fac0(puVar1,&local_4,param_1,0x3c);
        FUN_0057fb10(puVar1,&local_4,param_2);
        FUN_0057fb10(puVar1,&local_4,param_3);
        FUN_0057fb10(puVar1,&local_4,param_4);
        FUN_0057fb10(puVar1,&local_4,param_5);
        FUN_0057fb10(puVar1,&local_4,param_6);
        FUN_0057fb10(puVar1,&local_4,param_7);
        iVar2 = FUN_00580290(puVar3);
        if (-1 < iVar2) {
          FUN_00580610(param_3,*puVar3);
          return -(uint)(param_2 != 0) & param_3;
        }
        FUN_0056e1d0(puVar3);
      }
      goto LAB_00563002;
    }
    iVar2 = FUN_00562880(param_3,param_4,param_5,param_6,param_7,param_9);
    if (-1 < iVar2) {
      if (param_9 != 0) {
        FUN_00580f70(param_3);
      }
      return -(uint)(param_2 != 0) & param_3;
    }
  }
  else {
    param_3 = FUN_00550c90(*param_1);
    if (param_3 != 0xffffffff) goto LAB_00562e84;
  }
  if (param_9 != 0) {
    FUN_00580f70(param_3);
  }
LAB_00563002:
  if (param_2 != 0) {
    FUN_00580b80(param_3);
  }
  return 0xffffffff;
}

