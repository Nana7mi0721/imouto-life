
void FUN_0066dd50(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  bool bVar6;
  byte *pbVar7;
  int iVar8;
  
  uVar4 = *(ushort *)(param_1 + 0x150);
  bVar6 = false;
  if (uVar4 != 0) {
    iVar8 = 0;
    if (uVar4 != 0) {
      do {
        cVar3 = *(char *)(iVar8 + *(int *)(param_1 + 0x1b4));
        if (cVar3 != -1) {
          if (cVar3 != '\0') goto LAB_0066ddb5;
          bVar6 = true;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)uVar4);
    }
  }
  uVar5 = *(uint *)(param_1 + 0x7c);
  *(uint *)(param_1 + 0x7c) = uVar5 & 0xff7fffff;
  *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xffffdfff;
  if (!bVar6) {
    *(uint *)(param_1 + 0x7c) = uVar5 & 0xff7ffe7f;
  }
LAB_0066ddb5:
  uVar5 = *(uint *)(param_1 + 0x7c);
  if (((uVar5 & 0x100) != 0) && ((uVar5 & 0x1000) != 0)) {
    pbVar7 = (byte *)((uint)*(byte *)(param_1 + 0x168) * 3 + *(int *)(param_1 + 0x144));
    *(ushort *)(param_1 + 0x16a) = (ushort)*pbVar7;
    *(ushort *)(param_1 + 0x16c) = (ushort)pbVar7[1];
    *(ushort *)(param_1 + 0x16e) = (ushort)pbVar7[2];
    if (((uVar5 & 0x80000) != 0) && ((uVar5 & 0x2000000) == 0)) {
      iVar8 = 0;
      if (uVar4 != 0) {
        do {
          pcVar1 = (char *)(*(int *)(param_1 + 0x1b4) + iVar8);
          pcVar2 = (char *)(*(int *)(param_1 + 0x1b4) + iVar8);
          iVar8 = iVar8 + 1;
          *pcVar2 = -1 - *pcVar1;
        } while (iVar8 < (int)(uint)uVar4);
      }
    }
  }
  return;
}

