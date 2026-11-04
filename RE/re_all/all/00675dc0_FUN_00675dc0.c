
undefined4 FUN_00675dc0(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x2a8) != 0) {
    FUN_0066cb60(param_1,*(int *)(param_1 + 0x2a8));
    *(undefined4 *)(param_1 + 0x2a8) = 0;
  }
  uVar1 = *(uint *)(param_1 + 0x29c);
  uVar3 = 0xffffffff;
  if ((uVar1 != 0) && (uVar1 != 0xffffffff)) {
    uVar3 = uVar1;
  }
  if (param_2 <= uVar3) {
    uVar2 = *(undefined4 *)(param_1 + 0x11c);
    *(undefined1 *)(param_1 + 0x2a4) = 0;
    *(char *)(param_1 + 0x2a0) = (char)((uint)uVar2 >> 0x18);
    *(char *)(param_1 + 0x2a2) = (char)((uint)uVar2 >> 8);
    *(char *)(param_1 + 0x2a1) = (char)((uint)uVar2 >> 0x10);
    *(undefined1 *)(param_1 + 0x2a3) = *(undefined1 *)(param_1 + 0x11c);
    *(uint *)(param_1 + 0x2ac) = param_2;
    *(undefined1 *)(param_1 + 0x2b0) = *(undefined1 *)(param_1 + 0x74);
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x2a8) = 0;
    }
    else {
      uVar2 = FUN_0066cb30(param_1,param_2);
      *(undefined4 *)(param_1 + 0x2a8) = uVar2;
    }
  }
  if (*(int *)(param_1 + 0x2a8) == 0) {
    if (param_2 != 0) {
      FUN_00673140(param_1,param_2);
      FUN_00668b90(param_1,s_unknown_chunk_exceeds_memory_lim_00a0d180);
      return 0;
    }
  }
  else if (param_2 != 0) {
    FUN_00673110(param_1,*(int *)(param_1 + 0x2a8),param_2);
  }
  FUN_00673140(param_1,0);
  return 1;
}

