
void FUN_00573e90(int *param_1,uint *param_2,int *param_3,int param_4)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = *param_2;
  if (uVar1 < 0x80) {
    if (1 < (uint)(param_4 - *param_3)) {
      if ((byte *)*param_1 != (byte *)0x0) {
        *(byte *)*param_1 = (byte)*param_2;
        *param_1 = *param_1 + 1;
      }
      *param_3 = *param_3 + 1;
      return;
    }
  }
  else if (uVar1 < 0x800) {
    if (2 < (uint)(param_4 - *param_3)) {
      if ((byte *)*param_1 != (byte *)0x0) {
        *(byte *)*param_1 = (byte)(uVar1 >> 6) & 0x1f | 0xc0;
        *(byte *)(*param_1 + 1) = (byte)*param_2 & 0x3f | 0x80;
        *param_1 = *param_1 + 2;
      }
      *param_3 = *param_3 + 2;
      return;
    }
  }
  else if (uVar1 < 0x10000) {
    if (3 < (uint)(param_4 - *param_3)) {
      if ((byte *)*param_1 != (byte *)0x0) {
        *(byte *)*param_1 = (byte)(uVar1 >> 0xc) & 0xf | 0xe0;
        *(byte *)(*param_1 + 1) = (byte)(*param_2 >> 6) & 0x3f | 0x80;
        *(byte *)(*param_1 + 2) = (byte)*param_2 & 0x3f | 0x80;
        *param_1 = *param_1 + 3;
      }
      *param_3 = *param_3 + 3;
      return;
    }
  }
  else if (uVar1 < 0x200000) {
    if (4 < (uint)(param_4 - *param_3)) {
      if ((byte *)*param_1 != (byte *)0x0) {
        *(byte *)*param_1 = (byte)(uVar1 >> 0x12) & 7 | 0xf0;
        *(byte *)(*param_1 + 1) = (byte)(*param_2 >> 0xc) & 0x3f | 0x80;
        *(byte *)(*param_1 + 2) = (byte)(*param_2 >> 6) & 0x3f | 0x80;
        *(byte *)(*param_1 + 3) = (byte)*param_2 & 0x3f | 0x80;
        *param_1 = *param_1 + 4;
      }
      *param_3 = *param_3 + 4;
      return;
    }
  }
  else {
    bVar2 = (byte)(uVar1 >> 0x18);
    if (uVar1 < 0x4000000) {
      if (5 < (uint)(param_4 - *param_3)) {
        if ((byte *)*param_1 != (byte *)0x0) {
          *(byte *)*param_1 = bVar2 & 3 | 0xf8;
          *(byte *)(*param_1 + 1) = (byte)(*param_2 >> 0x12) & 0x3f | 0x80;
          *(byte *)(*param_1 + 2) = (byte)(*param_2 >> 0xc) & 0x3f | 0x80;
          *(byte *)(*param_1 + 3) = (byte)(*param_2 >> 6) & 0x3f | 0x80;
          *(byte *)(*param_1 + 4) = (byte)*param_2 & 0x3f | 0x80;
          *param_1 = *param_1 + 5;
        }
        *param_3 = *param_3 + 5;
        return;
      }
    }
    else if ((uVar1 < 0x80000000) && (6 < (uint)(param_4 - *param_3))) {
      if ((byte *)*param_1 != (byte *)0x0) {
        *(byte *)*param_1 = bVar2 >> 6 & 1 | 0xfc;
        *(byte *)(*param_1 + 1) = *(byte *)((int)param_2 + 3) & 0x3f | 0x80;
        *(byte *)(*param_1 + 2) = (byte)(*param_2 >> 0x12) & 0x3f | 0x80;
        *(byte *)(*param_1 + 3) = (byte)(*param_2 >> 0xc) & 0x3f | 0x80;
        *(byte *)(*param_1 + 4) = (byte)(*param_2 >> 6) & 0x3f | 0x80;
        *(byte *)(*param_1 + 5) = (byte)*param_2 & 0x3f | 0x80;
        *param_1 = *param_1 + 6;
      }
      *param_3 = *param_3 + 6;
    }
  }
  return;
}

