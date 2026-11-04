
void FUN_0066e670(int param_1,byte *param_2,byte *param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  int local_10 [4];
  
  bVar2 = *(byte *)(param_1 + 8);
  if (bVar2 != 3) {
    bVar3 = *(byte *)(param_1 + 9);
    uVar5 = (uint)bVar3;
    if ((bVar2 & 2) == 0) {
      iVar9 = 1;
      iVar8 = uVar5 - param_3[3];
      local_10[0] = iVar8;
    }
    else {
      iVar8 = uVar5 - *param_3;
      local_10[0] = iVar8;
      local_10[1] = uVar5 - param_3[1];
      local_10[2] = uVar5 - param_3[2];
      iVar9 = 3;
    }
    if ((bVar2 & 4) != 0) {
      local_10[iVar9] = uVar5 - param_3[4];
      iVar9 = iVar9 + 1;
    }
    bVar4 = false;
    if (iVar9 != 0) {
      piVar6 = local_10;
      iVar7 = iVar9;
      local_10[0] = iVar8;
      do {
        if ((*piVar6 < 1) || ((int)uVar5 <= *piVar6)) {
          *piVar6 = 0;
          iVar8 = local_10[0];
        }
        else {
          bVar4 = true;
        }
        piVar6 = piVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      if (bVar4) {
        switch(bVar3) {
        case 2:
          pbVar10 = param_2 + *(int *)(param_1 + 4);
          if (param_2 < pbVar10) {
            do {
              *param_2 = *param_2 >> 1 & 0x55;
              param_2 = param_2 + 1;
            } while (param_2 < pbVar10);
            return;
          }
          break;
        case 4:
          iVar9 = 0xf >> ((byte)iVar8 & 0x1f);
          pbVar10 = param_2 + *(int *)(param_1 + 4);
          if (param_2 < pbVar10) {
            while( true ) {
              *param_2 = *param_2 >> ((byte)iVar8 & 0x1f) & ((byte)iVar9 | (byte)(iVar9 << 4));
              param_2 = param_2 + 1;
              if (pbVar10 <= param_2) break;
              iVar8 = local_10[0];
            }
            return;
          }
          break;
        case 8:
          pbVar10 = param_2 + *(int *)(param_1 + 4);
          iVar8 = 0;
          if (param_2 < pbVar10) {
            do {
              pbVar1 = (byte *)(local_10 + iVar8);
              iVar8 = iVar8 + 1;
              if (iVar9 <= iVar8) {
                iVar8 = 0;
              }
              *param_2 = *param_2 >> (*pbVar1 & 0x1f);
              param_2 = param_2 + 1;
            } while (param_2 < pbVar10);
            return;
          }
          break;
        case 0x10:
          pbVar10 = param_2 + *(int *)(param_1 + 4);
          iVar8 = 0;
          for (; param_2 < pbVar10; param_2 = param_2 + 2) {
            iVar7 = (int)(uint)CONCAT11(*param_2,param_2[1]) >> ((byte)local_10[iVar8] & 0x1f);
            iVar8 = iVar8 + 1;
            if (iVar9 <= iVar8) {
              iVar8 = 0;
            }
            *param_2 = (byte)((uint)iVar7 >> 8);
            param_2[1] = (byte)iVar7;
          }
        }
      }
    }
  }
  return;
}

