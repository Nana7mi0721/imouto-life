
void FUN_0079f570(short *param_1,short *param_2,int param_3)

{
  byte *pbVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  short *psVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int *local_9c;
  int *local_98;
  int local_94;
  int local_8c [17];
  int local_48 [9];
  int local_24 [9];
  
  iVar11 = 0;
  local_8c[0] = 0;
  local_9c = (int *)&DAT_00838854;
  if (param_3 != 0x10) {
    local_9c = (int *)&DAT_00838864;
  }
  if (0 < param_3) {
    do {
      sVar2 = *param_2;
      param_2 = param_2 + 1;
      iVar6 = (int)sVar2 >> 8;
      pbVar1 = (byte *)((int)local_9c + iVar11);
      iVar11 = iVar11 + 1;
      local_8c[*pbVar1 + 1] =
           (((int)sVar2 + iVar6 * -0x100) *
            ((int)*(short *)(&DAT_00838886 + iVar6 * 2) - (int)*(short *)(&DAT_00838884 + iVar6 * 2)
            ) + *(short *)(&DAT_00838884 + iVar6 * 2) * 0x100 >> 3) + 1 >> 1;
    } while (iVar11 < param_3);
  }
  iVar11 = param_3 >> 1;
  local_48[0] = 0x10000;
  local_48[1] = -local_8c[1];
  local_98 = (int *)0x1;
  if (1 < iVar11) {
    local_9c = local_8c + 3;
    piVar10 = local_48;
    do {
      piVar10 = piVar10 + 1;
      iVar6 = *local_9c;
      __allmul(*piVar10,*piVar10 >> 0x1f,iVar6,iVar6 >> 0x1f);
      __allshr();
      iVar3 = __allshr();
      piVar10[1] = piVar10[-1] * 2 - iVar3;
      if (1 < (int)local_98) {
        local_94 = (int)local_98 + -1;
        piVar9 = piVar10;
        do {
          __allmul(piVar9[-1],piVar9[-1] >> 0x1f,iVar6,iVar6 >> 0x1f);
          __allshr();
          iVar3 = __allshr();
          *piVar9 = *piVar9 + (piVar9[-2] - iVar3);
          piVar9 = piVar9 + -1;
          local_94 = local_94 + -1;
        } while (local_94 != 0);
      }
      iVar6 = *local_9c;
      local_9c = local_9c + 2;
      local_98 = (int *)((int)local_98 + 1);
      local_48[1] = local_48[1] - iVar6;
    } while ((int)local_98 < iVar11);
  }
  local_24[0] = 0x10000;
  local_24[1] = -local_8c[2];
  local_9c = (int *)0x1;
  if (1 < iVar11) {
    local_98 = local_8c + 4;
    piVar10 = local_24;
    do {
      piVar10 = piVar10 + 1;
      iVar6 = *local_98;
      __allmul(*piVar10,*piVar10 >> 0x1f,iVar6,iVar6 >> 0x1f);
      __allshr();
      iVar3 = __allshr();
      piVar10[1] = piVar10[-1] * 2 - iVar3;
      if (1 < (int)local_9c) {
        local_94 = (int)local_9c + -1;
        piVar9 = piVar10;
        do {
          __allmul(piVar9[-1],piVar9[-1] >> 0x1f,iVar6,iVar6 >> 0x1f);
          __allshr();
          iVar3 = __allshr();
          *piVar9 = *piVar9 + (piVar9[-2] - iVar3);
          piVar9 = piVar9 + -1;
          local_94 = local_94 + -1;
        } while (local_94 != 0);
      }
      iVar6 = *local_98;
      local_98 = local_98 + 2;
      local_9c = (int *)((int)local_9c + 1);
      local_24[1] = local_24[1] - iVar6;
    } while ((int)local_9c < iVar11);
  }
  iVar6 = 0;
  if (0 < iVar11) {
    piVar10 = local_8c + param_3;
    do {
      iVar3 = local_48[iVar6];
      iVar4 = local_24[iVar6];
      local_8c[iVar6 + 1] = -((local_24[iVar6 + 1] - iVar4) + local_48[iVar6 + 1] + iVar3);
      *piVar10 = (local_24[iVar6 + 1] - iVar4) - (local_48[iVar6 + 1] + iVar3);
      iVar6 = iVar6 + 1;
      piVar10 = piVar10 + -1;
    } while (iVar6 < iVar11);
  }
  iVar11 = 0;
  do {
    iVar6 = 0;
    iVar3 = 0;
    if (0 < param_3) {
      piVar10 = local_8c;
      do {
        piVar10 = piVar10 + 1;
        iVar4 = *piVar10;
        if (iVar4 < 1) {
          iVar4 = -iVar4;
        }
        if (iVar6 < iVar4) {
          iVar6 = iVar4;
          local_8c[0] = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_3);
    }
    iVar6 = (iVar6 >> 4) + 1 >> 1;
    if (iVar6 < 0x8000) break;
    if (0x27ffd < iVar6) {
      iVar6 = 0x27ffe;
    }
    FUN_0079fda0(local_8c + 1,param_3,
                 ((0x7fff - iVar6) * 0x4000) / ((local_8c[0] + 1) * iVar6 >> 2) + 0xffbe);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 10);
  if (iVar11 == 10) {
    if (0 < param_3) {
      piVar10 = local_8c;
      psVar8 = param_1;
      iVar11 = param_3;
      do {
        piVar10 = piVar10 + 1;
        uVar5 = (*piVar10 >> 4) + 1;
        uVar7 = uVar5 & 0xfffffffe;
        if ((int)uVar7 < 0xffff) {
          if ((int)uVar7 < -0x10000) {
            sVar2 = -0x8000;
          }
          else {
            sVar2 = (short)((int)uVar5 >> 1);
          }
        }
        else {
          sVar2 = 0x7fff;
        }
        *psVar8 = sVar2;
        *piVar10 = (int)sVar2 << 5;
        psVar8 = psVar8 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
  }
  else if (0 < param_3) {
    piVar10 = local_8c;
    psVar8 = param_1;
    iVar11 = param_3;
    do {
      piVar10 = piVar10 + 1;
      *psVar8 = (short)((*piVar10 >> 4) + 1 >> 1);
      iVar11 = iVar11 + -1;
      psVar8 = psVar8 + 1;
    } while (iVar11 != 0);
  }
  iVar11 = 0;
  do {
    iVar6 = FUN_0079f0f0(param_1,param_3);
    if (0x1a36d < iVar6) {
      return;
    }
    FUN_0079fda0(local_8c + 1,param_3,0x10000 - (2 << ((byte)iVar11 & 0x1f)));
    if (0 < param_3) {
      piVar10 = local_8c;
      psVar8 = param_1;
      iVar6 = param_3;
      do {
        piVar10 = piVar10 + 1;
        *psVar8 = (short)((*piVar10 >> 4) + 1 >> 1);
        iVar6 = iVar6 + -1;
        psVar8 = psVar8 + 1;
      } while (iVar6 != 0);
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0x10);
  return;
}

