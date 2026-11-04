
void FUN_006707d0(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_1 + 2);
  iVar6 = *param_1;
  if ((bVar1 & 4) != 0) {
    if (*(char *)((int)param_1 + 9) == '\b') {
      iVar3 = *(int *)(param_3 + 0x198);
      if (iVar3 != 0) {
        pbVar5 = (byte *)(param_2 + -1);
        if (iVar6 == 0) {
          return;
        }
        do {
          pbVar5 = pbVar5 + (-(uint)((bVar1 & 2) != 0) & 2) + 2;
          *pbVar5 = *(byte *)((uint)*pbVar5 + iVar3);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        return;
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      iVar3 = *(int *)(param_3 + 0x1a0);
      uVar4 = *(undefined4 *)(param_3 + 0x188);
      if (iVar3 != 0) {
        pbVar5 = (byte *)(param_2 + -2);
        if (iVar6 == 0) {
          return;
        }
        do {
          pbVar5 = pbVar5 + (-(uint)((bVar1 & 2) != 0) & 4) + 4;
          uVar2 = *(undefined2 *)
                   (*(int *)(iVar3 + (uint)(pbVar5[1] >> ((byte)uVar4 & 0x1f)) * 4) +
                   (uint)*pbVar5 * 2);
          pbVar5[1] = (byte)uVar2;
          *pbVar5 = (byte)((ushort)uVar2 >> 8);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        return;
      }
    }
  }
  FUN_006687b0(param_3,s_png_do_encode_alpha__unexpected_c_00a0c7c4);
  return;
}

