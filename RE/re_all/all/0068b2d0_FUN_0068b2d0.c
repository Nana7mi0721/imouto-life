
int FUN_0068b2d0(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0x1b0);
  iVar3 = *(int *)(iVar2 + 0xc);
  do {
    if (0x7fff < iVar3) {
      bVar1 = *param_2;
      uVar4 = (uint)bVar1;
      iVar3 = *(int *)(&DAT_00823704 + (uVar4 & 0x7f) * 4);
      bVar6 = (byte)((uint)iVar3 >> 8);
      iVar5 = iVar3 >> 0x10;
      iVar7 = *(int *)(iVar2 + 0xc) - iVar5;
      *(int *)(iVar2 + 0xc) = iVar7;
      iVar7 = iVar7 << ((byte)*(undefined4 *)(iVar2 + 0x10) & 0x1f);
      if (*(int *)(iVar2 + 8) < iVar7) {
        if (*(int *)(iVar2 + 0xc) < 0x8000) {
          if (*(int *)(iVar2 + 0xc) < iVar5) {
            *param_2 = bVar1 & 0x80 ^ (byte)iVar3;
            return (int)(uVar4 ^ 0x80) >> 7;
          }
          *param_2 = bVar1 & 0x80 ^ bVar6;
        }
        return (int)uVar4 >> 7;
      }
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) - iVar7;
      iVar7 = *(int *)(iVar2 + 0xc);
      *(int *)(iVar2 + 0xc) = iVar5;
      if (iVar7 < iVar5) {
        *param_2 = bVar1 & 0x80 ^ bVar6;
        return (int)uVar4 >> 7;
      }
      *param_2 = bVar1 & 0x80 ^ (byte)iVar3;
      return (int)(uVar4 ^ 0x80) >> 7;
    }
    iVar3 = *(int *)(iVar2 + 0x10) + -1;
    *(int *)(iVar2 + 0x10) = iVar3;
    if (iVar3 < 0) {
      if (*(int *)(param_1 + 0x194) == 0) {
        uVar4 = FUN_0068b410(param_1);
        if (uVar4 == 0xff) {
          do {
            iVar3 = FUN_0068b410(param_1);
          } while (iVar3 == 0xff);
          if (iVar3 != 0) {
            *(int *)(param_1 + 0x194) = iVar3;
            goto LAB_0068b331;
          }
          uVar4 = 0xff;
        }
      }
      else {
LAB_0068b331:
        uVar4 = 0;
      }
      iVar3 = *(int *)(iVar2 + 0x10);
      iVar5 = iVar3 + 8;
      *(uint *)(iVar2 + 8) = *(int *)(iVar2 + 8) << 8 | uVar4;
      *(int *)(iVar2 + 0x10) = iVar5;
      if ((iVar5 < 0) && (iVar3 = iVar3 + 9, *(int *)(iVar2 + 0x10) = iVar3, iVar3 == 0)) {
        *(undefined4 *)(iVar2 + 0xc) = 0x8000;
      }
    }
    iVar3 = *(int *)(iVar2 + 0xc) * 2;
    *(int *)(iVar2 + 0xc) = iVar3;
  } while( true );
}

