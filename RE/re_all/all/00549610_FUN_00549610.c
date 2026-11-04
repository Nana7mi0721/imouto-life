
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00549610(char *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,int param_7
            )

{
  float fVar1;
  undefined2 uVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  
  if ((*param_1 != '\0') && (iVar3 = FUN_00546d90(param_1,1), iVar3 < 0)) {
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x428) <= param_2) || (*(uint *)(param_1 + 0x42c) <= param_3)) {
    return 0xffffffff;
  }
  if (param_1[3] == '\0') {
    uVar5 = FUN_005440f0(param_1,param_4,param_5,param_6,param_7);
    switch(param_1[4]) {
    case '\x01':
      *(char *)(*(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434) + param_2) =
           (char)uVar5;
      return 0;
    case '\x02':
      *(short *)(*(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434) + param_2 * 2) =
           (short)uVar5;
      return 0;
    case '\x03':
      puVar6 = (undefined2 *)
               (*(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434) + param_2 * 3);
      *puVar6 = (short)uVar5;
      *(char *)(puVar6 + 1) = (char)((uint)uVar5 >> 0x10);
      return 0;
    case '\x04':
      *(undefined4 *)(*(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434) + param_2 * 4)
           = uVar5;
      return 0;
    }
  }
  else if (param_1[2] == '\x10') {
    puVar6 = (undefined2 *)
             (*(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434) + param_2 * 8);
    if (param_1[1] != '\0') {
      uVar2 = FUN_00540880((float)param_4 / (float)_DAT_0081ec30);
      *puVar6 = uVar2;
    }
    if (1 < (byte)param_1[1]) {
      uVar2 = FUN_00540880((float)param_5 / (float)_DAT_0081ec30);
      puVar6[1] = uVar2;
    }
    if (2 < (byte)param_1[1]) {
      uVar2 = FUN_00540880((float)param_6 / (float)_DAT_0081ec30);
      puVar6[2] = uVar2;
    }
    if (3 < (byte)param_1[1]) {
      uVar2 = FUN_00540880((float)param_7 / (float)_DAT_0081ec30);
      puVar6[3] = uVar2;
      return 0;
    }
  }
  else {
    if (param_1[2] != ' ') {
      return 0xffffffff;
    }
    fVar1 = (float)_DAT_0081ec30;
    pfVar4 = (float *)(*(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434) +
                      param_2 * 0x10);
    if (param_1[1] != '\0') {
      *pfVar4 = (float)param_4 / fVar1;
    }
    if (1 < (byte)param_1[1]) {
      pfVar4[1] = (float)param_5 / fVar1;
    }
    if (2 < (byte)param_1[1]) {
      pfVar4[2] = (float)param_6 / fVar1;
    }
    if (3 < (byte)param_1[1]) {
      pfVar4[3] = (float)param_7 / fVar1;
      return 0;
    }
  }
  return 0;
}

