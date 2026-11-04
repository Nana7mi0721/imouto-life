
void FUN_0067ff70(int param_1,int param_2,int param_3)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  uint local_4;
  
  uVar2 = *(ushort *)(param_2 + 2);
  iVar8 = 0;
  local_4 = 0xffffffff;
  iVar5 = 7;
  iVar7 = 4;
  if (uVar2 == 0) {
    iVar5 = 0x8a;
    iVar7 = 3;
  }
  *(undefined2 *)(param_2 + 6 + param_3 * 4) = 0xffff;
  if (-1 < param_3) {
    puVar6 = (ushort *)(param_2 + 6);
    uVar3 = (uint)uVar2;
    param_2 = param_3 + 1;
    do {
      uVar4 = (uint)*puVar6;
      iVar8 = iVar8 + 1;
      if ((iVar5 <= iVar8) || (uVar3 != uVar4)) {
        if (iVar8 < iVar7) {
          psVar1 = (short *)(param_1 + 0xa7c + uVar3 * 4);
          *psVar1 = *psVar1 + (short)iVar8;
        }
        else if (uVar3 == 0) {
          if (iVar8 < 0xb) {
            *(short *)(param_1 + 0xac0) = *(short *)(param_1 + 0xac0) + 1;
          }
          else {
            *(short *)(param_1 + 0xac4) = *(short *)(param_1 + 0xac4) + 1;
          }
        }
        else {
          if (uVar3 != local_4) {
            psVar1 = (short *)(param_1 + 0xa7c + uVar3 * 4);
            *psVar1 = *psVar1 + 1;
          }
          *(short *)(param_1 + 0xabc) = *(short *)(param_1 + 0xabc) + 1;
        }
        iVar8 = 0;
        local_4 = uVar3;
        if (uVar4 == 0) {
          iVar5 = 0x8a;
          iVar7 = 3;
        }
        else if (uVar3 == uVar4) {
          iVar5 = 6;
          iVar7 = 3;
        }
        else {
          iVar5 = 7;
          iVar7 = 4;
        }
      }
      puVar6 = puVar6 + 2;
      param_2 = param_2 + -1;
      uVar3 = uVar4;
    } while (param_2 != 0);
  }
  return;
}

