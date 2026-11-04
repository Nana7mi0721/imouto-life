
void FUN_00679150(int param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(byte *)(param_1 + 0x15c) * (uint)*(byte *)(param_1 + 0x159);
  if (uVar4 < 8) {
    uVar1 = *(int *)(param_1 + 0x100) * uVar4 + 7 >> 3;
  }
  else {
    uVar1 = (uVar4 >> 3) * *(int *)(param_1 + 0x100);
  }
  *(undefined1 *)(param_1 + 0x15f) = *(undefined1 *)(param_1 + 0x15a);
  *(char *)(param_1 + 0x15e) = (char)uVar4;
  puVar2 = (undefined1 *)FUN_0066caf0(param_1,uVar1 + 1);
  *(undefined1 **)(param_1 + 0x124) = puVar2;
  *puVar2 = 0;
  if ((*(byte *)(param_1 + 0x156) & 0x10) != 0) {
    puVar2 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
    *(undefined1 **)(param_1 + 0x128) = puVar2;
    *puVar2 = 1;
  }
  if ((*(byte *)(param_1 + 0x156) & 0xe0) != 0) {
    uVar3 = FUN_0066c950(param_1,uVar1 + 1);
    *(undefined4 *)(param_1 + 0x120) = uVar3;
    if ((*(byte *)(param_1 + 0x156) & 0x20) != 0) {
      puVar2 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
      *(undefined1 **)(param_1 + 300) = puVar2;
      *puVar2 = 2;
    }
    if ((*(byte *)(param_1 + 0x156) & 0x40) != 0) {
      puVar2 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
      *(undefined1 **)(param_1 + 0x130) = puVar2;
      *puVar2 = 3;
    }
    if ((*(byte *)(param_1 + 0x156) & 0x80) != 0) {
      puVar2 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
      *(undefined1 **)(param_1 + 0x134) = puVar2;
      *puVar2 = 4;
    }
  }
  if (*(char *)(param_1 + 0x154) == '\0') {
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x104);
    *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0x100);
    return;
  }
  if ((*(byte *)(param_1 + 0x7c) & 2) == 0) {
    *(uint *)(param_1 + 0x108) =
         ((*(int *)(param_1 + 0x104) - (DAT_0081f114 & 0xff)) + -1 + (DAT_0081f11c & 0xff)) /
         (DAT_0081f11c & 0xff);
    *(uint *)(param_1 + 0x10c) =
         ((*(int *)(param_1 + 0x100) - (DAT_0081f104 & 0xff)) + -1 + (DAT_0081f10c & 0xff)) /
         (DAT_0081f10c & 0xff);
    return;
  }
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x104);
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0x100);
  return;
}

