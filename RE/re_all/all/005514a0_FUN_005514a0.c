
undefined4
FUN_005514a0(int *param_1,uint param_2,int *param_3,int param_4,int param_5,int param_6,int param_7)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (*param_1 != 0) {
    return 0xffffffff;
  }
  param_1[0x13] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = param_7;
  param_1[0x11] = param_5;
  param_1[0x12] = param_6;
  if (DAT_00a83c64 == 0) {
    iVar2 = FUN_0057f560(param_1,param_2,param_3,param_4,param_7);
    if (iVar2 < 0) goto LAB_0055164a;
  }
  else {
    if (param_4 == 0) {
      puVar1 = (uint *)FUN_0056e030(param_2 + 0x20,
                                    "..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x1faf);
      if (puVar1 == (uint *)0x0) {
        puVar1 = (uint *)0x0;
      }
      else {
        *puVar1 = (int)puVar1 + 0x1fU & 0xfffffff0;
        puVar1[2] = param_2;
        puVar1[3] = 1;
        puVar1[1] = 0;
      }
    }
    else {
      puVar1 = *(uint **)(param_4 + 0x4c);
      puVar1[3] = puVar1[3] + 1;
    }
    param_1[0x13] = (int)puVar1;
    if (puVar1 == (uint *)0x0) goto LAB_0055164a;
  }
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  if (param_4 == 0) {
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = -1;
    param_1[0xb] = param_2 / *(ushort *)(param_3 + 3);
    param_1[0xc] = *param_3;
    param_1[0xd] = param_3[1];
    param_1[0xe] = param_3[2];
    param_1[0xf] = param_3[3];
    *(short *)(param_1 + 0x10) = (short)param_3[4];
  }
  else {
    param_1[1] = *(int *)(param_4 + 4);
    param_1[2] = *(int *)(param_4 + 8);
    param_1[3] = *(int *)(param_4 + 0xc);
    param_1[4] = *(int *)(param_4 + 0x10);
    param_1[5] = *(int *)(param_4 + 0x14);
    param_1[6] = *(int *)(param_4 + 0x18);
    param_1[7] = *(int *)(param_4 + 0x1c);
    param_1[8] = *(int *)(param_4 + 0x20);
    param_1[9] = *(int *)(param_4 + 0x24);
    param_1[10] = *(int *)(param_4 + 0x28);
    param_1[0xb] = *(int *)(param_4 + 0x2c);
    param_1[0xc] = *(int *)(param_4 + 0x30);
    param_1[0xd] = *(int *)(param_4 + 0x34);
    param_1[0xe] = *(int *)(param_4 + 0x38);
    param_1[0xf] = *(int *)(param_4 + 0x3c);
    *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_4 + 0x40);
  }
  if (param_7 != 0) {
    param_1[0x2f] = 1;
    if ((DAT_00a83c64 == 0) && (iVar2 = FUN_0057e450(param_1,param_4,param_7), iVar2 < 0)) {
LAB_0055164a:
      iVar2 = param_1[0x13];
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + -1;
        if ((*(int *)(iVar2 + 0xc) < 1) && (-1 < *(int *)(iVar2 + 0xc))) {
          FUN_0056e1d0(iVar2);
        }
        param_1[0x13] = 0;
      }
      return 0xffffffff;
    }
    if (param_4 != 0) {
      piVar3 = (int *)(param_4 + 0x74);
      piVar4 = param_1 + 0x1d;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      param_1[0x2d] = *(int *)(param_4 + 0xb4);
      param_1[0x2e] = *(int *)(param_4 + 0xb8);
      *param_1 = 1;
      return 0;
    }
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0;
    param_1[0x22] = 0x3f800000;
    param_1[0x23] = 0;
    param_1[0x24] = 0x3f800000;
    param_1[0x25] = 0;
    param_1[0x26] = 0;
    param_1[0x27] = 0;
    param_1[0x28] = 0;
  }
  *param_1 = 1;
  return 0;
}

