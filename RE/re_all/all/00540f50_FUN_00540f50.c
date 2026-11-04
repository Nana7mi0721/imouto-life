
uint FUN_00540f50(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x434) == 0) {
    return 0;
  }
  uVar2 = (uint)*(byte *)(param_1 + 4);
  puVar1 = (uint *)(uVar2 * param_2 +
                   *(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434));
  if (uVar2 == 2) {
    uVar3 = (uint)(ushort)*puVar1;
  }
  else if (uVar2 == 3) {
    uVar3 = *puVar1 & 0xffffff;
  }
  else if (uVar2 == 4) {
    uVar3 = *puVar1;
  }
  uVar2 = ((*(uint *)(param_1 + 0x18) & uVar3) >> (*(byte *)(param_1 + 0xe) & 0x1f)) <<
          (8U - *(char *)(param_1 + 10) & 0x1f) |
          ((*(uint *)(param_1 + 0x14) & uVar3) >> (*(byte *)(param_1 + 0xd) & 0x1f)) <<
          (0x10U - *(char *)(param_1 + 9) & 0x1f) |
          ((*(uint *)(param_1 + 0x10) & uVar3) >> (*(byte *)(param_1 + 0xc) & 0x1f)) <<
          (0x18U - *(char *)(param_1 + 8) & 0x1f);
  if (*(char *)(param_1 + 0xb) != '\0') {
    uVar2 = uVar2 | ((*(uint *)(param_1 + 0x1c) & uVar3) >> (*(byte *)(param_1 + 0xf) & 0x1f)) <<
                    (0x20U - *(char *)(param_1 + 0xb) & 0x1f);
  }
  return uVar2;
}

