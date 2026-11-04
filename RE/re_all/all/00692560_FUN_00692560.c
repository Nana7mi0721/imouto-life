
void FUN_00692560(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar1 = *param_2;
  iVar5 = *(int *)(&DAT_00823704 + (bVar1 & 0x7f) * 4);
  iVar2 = *(int *)(param_1 + 0x198);
  iVar4 = iVar5 >> 0x10;
  iVar6 = *(int *)(iVar2 + 0x10) - iVar4;
  *(int *)(iVar2 + 0x10) = iVar6;
  if (param_3 == (int)(uint)bVar1 >> 7) {
    if (0x7fff < iVar6) {
      return;
    }
    if (iVar6 < iVar4) {
      *(int *)(iVar2 + 0x10) = iVar4;
      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + iVar6;
    }
    *param_2 = bVar1 & 0x80 ^ (byte)((uint)iVar5 >> 8);
  }
  else {
    if (iVar4 <= iVar6) {
      *(int *)(iVar2 + 0x10) = iVar4;
      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + iVar6;
    }
    *param_2 = bVar1 & 0x80 ^ (byte)iVar5;
  }
  do {
    iVar4 = *(int *)(iVar2 + 0xc) << 1;
    iVar5 = *(int *)(iVar2 + 0x1c) + -1;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) << 1;
    *(int *)(iVar2 + 0xc) = iVar4;
    *(int *)(iVar2 + 0x1c) = iVar5;
    if (iVar5 == 0) {
      uVar3 = iVar4 >> 0x13;
      if ((int)uVar3 < 0x100) {
        if (uVar3 != 0xff) {
          if (*(int *)(iVar2 + 0x20) == 0) {
            *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
          }
          else if (-1 < *(int *)(iVar2 + 0x20)) {
            iVar5 = *(int *)(iVar2 + 0x18);
            while (iVar5 != 0) {
              FUN_00692100(0,param_1);
              iVar5 = *(int *)(iVar2 + 0x18) + -1;
              *(int *)(iVar2 + 0x18) = iVar5;
            }
            FUN_00692100(*(undefined4 *)(iVar2 + 0x20),param_1);
          }
          if (*(int *)(iVar2 + 0x14) != 0) {
            iVar5 = *(int *)(iVar2 + 0x18);
            while (iVar5 != 0) {
              FUN_00692100(0,param_1);
              iVar5 = *(int *)(iVar2 + 0x18) + -1;
              *(int *)(iVar2 + 0x18) = iVar5;
            }
            do {
              FUN_00692100(0xff,param_1);
              FUN_00692100(0,param_1);
              iVar5 = *(int *)(iVar2 + 0x14) + -1;
              *(int *)(iVar2 + 0x14) = iVar5;
            } while (iVar5 != 0);
          }
          goto LAB_006926d9;
        }
        *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
      }
      else {
        if (-1 < *(int *)(iVar2 + 0x20)) {
          iVar5 = *(int *)(iVar2 + 0x18);
          while (iVar5 != 0) {
            FUN_00692100(0,param_1);
            iVar5 = *(int *)(iVar2 + 0x18) + -1;
            *(int *)(iVar2 + 0x18) = iVar5;
          }
          FUN_00692100(*(int *)(iVar2 + 0x20) + 1,param_1);
          if (*(int *)(iVar2 + 0x20) == 0xfe) {
            FUN_00692100(0,param_1);
          }
        }
        iVar5 = *(int *)(iVar2 + 0x14);
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + iVar5;
LAB_006926d9:
        *(uint *)(iVar2 + 0x20) = uVar3 & 0xff;
      }
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0x7ffff;
      *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + 8;
    }
    if (0x7fff < *(int *)(iVar2 + 0x10)) {
      return;
    }
  } while( true );
}

