
undefined1 FUN_00683090(int *param_1)

{
  char cVar1;
  
  if (param_1[0x65] == 0) {
    cVar1 = FUN_00680fc0(param_1);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  if (param_1[0x65] == *(int *)(param_1[0x6b] + 0x10) + 0xd0) {
    *(undefined4 *)(*param_1 + 0x14) = 100;
    *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[0x6b] + 0x10);
    (**(code **)(*param_1 + 4))(param_1,3);
    param_1[0x65] = 0;
  }
  else {
    cVar1 = (**(code **)(param_1[6] + 0x14))(param_1,*(int *)(param_1[0x6b] + 0x10));
    if (cVar1 == '\0') {
      return 0;
    }
  }
  *(uint *)(param_1[0x6b] + 0x10) = *(int *)(param_1[0x6b] + 0x10) + 1U & 7;
  return 1;
}

