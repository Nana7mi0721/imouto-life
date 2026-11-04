
int FUN_006850b0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x6a];
  if (*(char *)(iVar1 + 0x11) != '\0') {
    return 2;
  }
  while( true ) {
    iVar2 = (**(code **)(param_1[0x6b] + 4))(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    if (iVar2 != 1) break;
    if (*(int *)(iVar1 + 0x14) == 0) {
      if (*(char *)(iVar1 + 0x10) == '\0') {
        *(undefined4 *)(*param_1 + 0x14) = 0x24;
        (**(code **)*param_1)(param_1);
      }
      if (param_1[0x4c] != 0) {
        FUN_00684df0(param_1);
        return 1;
      }
    }
    else {
      if (*(int *)(iVar1 + 0x14) == 1) {
        FUN_006851b0(param_1);
      }
      if (param_1[0x4c] != 0) {
        *(undefined4 *)(iVar1 + 0x14) = 0;
        return 1;
      }
      *(undefined4 *)(iVar1 + 0x14) = 2;
    }
  }
  if (iVar2 != 2) {
    return iVar2;
  }
  *(undefined1 *)(iVar1 + 0x11) = 1;
  if (*(int *)(iVar1 + 0x14) == 0) {
    if (param_1[0x1f] < param_1[0x21]) {
      param_1[0x21] = param_1[0x1f];
    }
  }
  else if (*(char *)(param_1[0x6b] + 0xd) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x3e;
    (**(code **)*param_1)(param_1);
    return 2;
  }
  return 2;
}

