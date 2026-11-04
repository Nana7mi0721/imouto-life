
undefined4
FUN_00544290(int param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  if (((*(byte *)(param_1 + 8) == 8) && (*(char *)(param_1 + 9) == '\b')) &&
     (*(char *)(param_1 + 10) == '\b')) {
    if (param_3 != (uint *)0x0) {
      *param_3 = (*(uint *)(param_1 + 0x10) & param_2) >> (*(byte *)(param_1 + 0xc) & 0x1f);
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = (*(uint *)(param_1 + 0x14) & param_2) >> (*(byte *)(param_1 + 0xd) & 0x1f);
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = (*(uint *)(param_1 + 0x18) & param_2) >> (*(byte *)(param_1 + 0xe) & 0x1f);
    }
    bVar1 = *(byte *)(param_1 + 0xb);
    if (bVar1 != 0) {
      if (bVar1 == 8) {
        if (param_6 != (uint *)0x0) {
          *param_6 = (*(uint *)(param_1 + 0x1c) & param_2) >> (*(byte *)(param_1 + 0xf) & 0x1f);
          return 0;
        }
      }
      else if (param_6 != (uint *)0x0) {
        *param_6 = (((*(uint *)(param_1 + 0x1c) & param_2) >> (*(byte *)(param_1 + 0xf) & 0x1f)) *
                   0xff) / ((1 << (bVar1 & 0x1f)) - 1U);
        return 0;
      }
    }
  }
  else {
    bVar1 = *(byte *)(param_1 + 9);
    bVar2 = *(byte *)(param_1 + 10);
    bVar3 = *(byte *)(param_1 + 0xb);
    if (param_3 != (uint *)0x0) {
      *param_3 = (((*(uint *)(param_1 + 0x10) & param_2) >> (*(byte *)(param_1 + 0xc) & 0x1f)) *
                 0xff) / ((1 << (*(byte *)(param_1 + 8) & 0x1f)) - 1U);
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = (((*(uint *)(param_1 + 0x14) & param_2) >> (*(byte *)(param_1 + 0xd) & 0x1f)) *
                 0xff) / ((1 << (bVar1 & 0x1f)) - 1U);
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = (((*(uint *)(param_1 + 0x18) & param_2) >> (*(byte *)(param_1 + 0xe) & 0x1f)) *
                 0xff) / ((1 << (bVar2 & 0x1f)) - 1U);
    }
    if (param_6 != (uint *)0x0) {
      if (*(char *)(param_1 + 0xb) != '\0') {
        *param_6 = (((*(uint *)(param_1 + 0x1c) & param_2) >> (*(byte *)(param_1 + 0xf) & 0x1f)) *
                   0xff) / ((1 << (bVar3 & 0x1f)) - 1U);
        return 0;
      }
      *param_6 = 0;
    }
  }
  return 0;
}

