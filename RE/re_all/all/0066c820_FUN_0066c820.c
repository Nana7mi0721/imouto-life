
void FUN_0066c820(int param_1)

{
  uint uVar1;
  
  FUN_0066b390(param_1);
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x27c));
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x2c8));
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x2b8));
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x208));
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x20c));
  if ((*(uint *)(param_1 + 0x248) & 0x1000) != 0) {
    FUN_00668f10(param_1,*(undefined4 *)(param_1 + 0x144));
  }
  uVar1 = *(uint *)(param_1 + 0x248);
  *(uint *)(param_1 + 0x248) = uVar1 & 0xffffefff;
  if ((uVar1 & 0x2000) != 0) {
    FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x1b4));
  }
  *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) & 0xffffdfff;
  FUN_0067c510(param_1 + 0x84);
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x1dc));
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x2a8));
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x25c));
  return;
}

