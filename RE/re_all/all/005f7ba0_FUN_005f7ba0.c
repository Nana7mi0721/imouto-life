
int FUN_005f7ba0(int param_1,int *param_2,undefined4 *param_3,uint param_4,int param_5,code *param_6
                ,int param_7,int param_8)

{
  int *piVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = param_1;
  if ((param_1 == 0) || (param_6 == (code *)0x0)) {
    param_1 = -1;
  }
  else {
    param_1 = (*param_6)(param_1,0,0,1);
  }
  FUN_0056d380(param_2,0,0x2d0);
  piVar1 = param_2 + 6;
  *param_2 = iVar4;
  param_2[0xb0] = param_5;
  param_2[0xb1] = (int)param_6;
  param_2[0xb2] = param_7;
  param_2[0xb3] = param_8;
  FUN_006a86a0(piVar1);
  if (param_3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_006a8700(piVar1,param_4);
    for (uVar5 = param_4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar5 = param_4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_3;
      param_3 = (undefined4 *)((int)param_3 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    FUN_006a87a0(piVar1,param_4);
  }
  if (param_1 != -1) {
    param_2[1] = 1;
  }
  param_2[0xd] = 1;
  pvVar3 = _calloc(1,0x20);
  param_2[0x12] = (int)pvVar3;
  pvVar3 = _calloc(param_2[0xd],0x10);
  param_2[0x13] = (int)pvVar3;
  FUN_006a83f0(param_2 + 0x1e,0xffffffff);
  iVar4 = FUN_005f7cc0(param_2,param_2[0x12],param_2[0x13],param_2 + 0x17,0);
  if (iVar4 < 0) {
    *param_2 = 0;
    FUN_005f8a20(param_2);
    return iVar4;
  }
  param_2[0x16] = 1;
  return iVar4;
}

