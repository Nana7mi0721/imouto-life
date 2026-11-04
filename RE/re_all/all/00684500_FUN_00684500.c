
void FUN_00684500(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_1[5] != 100) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  *(undefined1 *)(param_1 + 0x3a) = 0;
  param_1[0x14] = param_2;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  switch(param_2) {
  case 0:
    iVar3 = param_1[9];
    param_1[0x13] = iVar3;
    if ((iVar3 < 1) || (10 < iVar3)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1b;
      *(int *)(*param_1 + 0x18) = param_1[0x13];
      *(undefined4 *)(*param_1 + 0x1c) = 10;
      (**(code **)*param_1)(param_1);
    }
    iVar3 = 0;
    if (0 < param_1[0x13]) {
      iVar4 = 0;
      do {
        piVar2 = (int *)(iVar4 + param_1[0x15]);
        iVar4 = iVar4 + 0x58;
        *piVar2 = iVar3;
        piVar2[2] = 1;
        piVar2[3] = 1;
        piVar2[4] = 0;
        piVar2[5] = 0;
        piVar2[6] = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[0x13]);
      return;
    }
    break;
  case 1:
    *(undefined1 *)(param_1 + 0x3a) = 1;
    param_1[0x13] = 1;
    puVar1 = (undefined4 *)param_1[0x15];
    *puVar1 = 1;
    puVar1[2] = 1;
    puVar1[3] = 1;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    return;
  case 2:
    puVar1 = (undefined4 *)param_1[0x15];
    *(undefined1 *)(param_1 + 0x3c) = 1;
    param_1[0x13] = 3;
    *puVar1 = 0x52;
    puVar1[2] = 1;
    puVar1[3] = 1;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0x58) = 0x47;
    *(undefined4 *)(iVar3 + 0x60) = 1;
    *(undefined4 *)(iVar3 + 100) = 1;
    *(undefined4 *)(iVar3 + 0x68) = 0;
    *(uint *)(iVar3 + 0x6c) = (uint)(param_1[0x3d] == 1);
    *(uint *)(iVar3 + 0x70) = (uint)(param_1[0x3d] == 1);
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0xc0) = 0;
    *(undefined4 *)(iVar3 + 0xc4) = 0;
    *(undefined4 *)(iVar3 + 200) = 0;
    *(undefined4 *)(iVar3 + 0xb0) = 0x42;
    *(undefined4 *)(iVar3 + 0xb8) = 1;
    *(undefined4 *)(iVar3 + 0xbc) = 1;
    return;
  case 3:
    puVar1 = (undefined4 *)param_1[0x15];
    *(undefined1 *)(param_1 + 0x3a) = 1;
    param_1[0x13] = 3;
    *puVar1 = 1;
    puVar1[2] = 2;
    puVar1[3] = 2;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0x58) = 2;
    *(undefined4 *)(iVar3 + 0x60) = 1;
    *(undefined4 *)(iVar3 + 100) = 1;
    *(undefined4 *)(iVar3 + 0x68) = 1;
    *(undefined4 *)(iVar3 + 0x6c) = 1;
    *(undefined4 *)(iVar3 + 0x70) = 1;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0xb0) = 3;
    *(undefined4 *)(iVar3 + 0xb8) = 1;
    *(undefined4 *)(iVar3 + 0xbc) = 1;
    *(undefined4 *)(iVar3 + 0xc0) = 1;
    *(undefined4 *)(iVar3 + 0xc4) = 1;
    *(undefined4 *)(iVar3 + 200) = 1;
    return;
  case 4:
    puVar1 = (undefined4 *)param_1[0x15];
    *(undefined1 *)(param_1 + 0x3c) = 1;
    param_1[0x13] = 4;
    *puVar1 = 0x43;
    puVar1[2] = 1;
    puVar1[3] = 1;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0x58) = 0x4d;
    *(undefined4 *)(iVar3 + 0x60) = 1;
    *(undefined4 *)(iVar3 + 100) = 1;
    *(undefined4 *)(iVar3 + 0x68) = 0;
    *(undefined4 *)(iVar3 + 0x6c) = 0;
    *(undefined4 *)(iVar3 + 0x70) = 0;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0xb0) = 0x59;
    *(undefined4 *)(iVar3 + 0xb8) = 1;
    *(undefined4 *)(iVar3 + 0xbc) = 1;
    *(undefined4 *)(iVar3 + 0xc0) = 0;
    *(undefined4 *)(iVar3 + 0xc4) = 0;
    *(undefined4 *)(iVar3 + 200) = 0;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0x108) = 0x4b;
    *(undefined4 *)(iVar3 + 0x110) = 1;
    *(undefined4 *)(iVar3 + 0x114) = 1;
    *(undefined4 *)(iVar3 + 0x118) = 0;
    *(undefined4 *)(iVar3 + 0x11c) = 0;
    *(undefined4 *)(iVar3 + 0x120) = 0;
    return;
  case 5:
    puVar1 = (undefined4 *)param_1[0x15];
    *(undefined1 *)(param_1 + 0x3c) = 1;
    param_1[0x13] = 4;
    *puVar1 = 1;
    puVar1[2] = 2;
    puVar1[3] = 2;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0x58) = 2;
    *(undefined4 *)(iVar3 + 0x60) = 1;
    *(undefined4 *)(iVar3 + 100) = 1;
    *(undefined4 *)(iVar3 + 0x68) = 1;
    *(undefined4 *)(iVar3 + 0x6c) = 1;
    *(undefined4 *)(iVar3 + 0x70) = 1;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0xb0) = 3;
    *(undefined4 *)(iVar3 + 0xb8) = 1;
    *(undefined4 *)(iVar3 + 0xbc) = 1;
    *(undefined4 *)(iVar3 + 0xc0) = 1;
    *(undefined4 *)(iVar3 + 0xc4) = 1;
    *(undefined4 *)(iVar3 + 200) = 1;
    iVar3 = param_1[0x15];
    *(undefined4 *)(iVar3 + 0x108) = 4;
    *(undefined4 *)(iVar3 + 0x110) = 2;
    *(undefined4 *)(iVar3 + 0x114) = 2;
    *(undefined4 *)(iVar3 + 0x118) = 0;
    *(undefined4 *)(iVar3 + 0x11c) = 0;
    *(undefined4 *)(iVar3 + 0x120) = 0;
    return;
  default:
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    (**(code **)*param_1)(param_1);
  }
  return;
}

