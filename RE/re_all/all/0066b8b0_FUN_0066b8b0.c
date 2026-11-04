
void FUN_0066b8b0(uint param_1,int *param_2,byte param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  bVar4 = 8 - param_3;
  iVar8 = 1 << (bVar4 & 0x1f);
  puVar2 = (undefined4 *)FUN_0066c950(param_1,iVar8 * 4);
  *param_2 = (int)puVar2;
  if (iVar8 != 0) {
    iVar9 = iVar8;
    puVar11 = puVar2;
    do {
      uVar3 = FUN_0066caf0(param_1,0x200);
      *puVar11 = uVar3;
      puVar11 = puVar11 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  uVar10 = 0;
  param_1 = 0;
  do {
    uVar1 = FUN_0066b2f0((param_1 * 0x101 & 0xffff) + 0x80,param_4);
    uVar5 = ((uint)uVar1 * ((1 << (0x10 - param_3 & 0x1f)) + -1) + 0x8000) / 0xffff + 1;
    if (uVar10 < uVar5) {
      do {
        uVar6 = 0xffU >> (param_3 & 0x1f) & uVar10;
        uVar7 = uVar10 >> (bVar4 & 0x1f);
        uVar10 = uVar10 + 1;
        *(short *)(puVar2[uVar6] + uVar7 * 2) = (short)(param_1 * 0x101);
      } while (uVar10 < uVar5);
    }
    param_1 = param_1 + 1;
  } while (param_1 < 0xff);
  if (uVar10 < (uint)(iVar8 << 8)) {
    do {
      uVar5 = uVar10 >> (bVar4 & 0x1f);
      uVar6 = 0xff >> (param_3 & 0x1f) & uVar10;
      uVar10 = uVar10 + 1;
      *(undefined2 *)(puVar2[uVar6] + uVar5 * 2) = 0xffff;
    } while (uVar10 < (uint)(iVar8 << 8));
  }
  return;
}

