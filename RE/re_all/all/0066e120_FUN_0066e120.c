
void FUN_0066e120(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x124) == 0) {
    FUN_00668620(param_1,s_NULL_row_buffer_00a0c7b4);
  }
  if (((*(uint *)(param_1 + 0x78) & 0x4000) != 0) && ((*(uint *)(param_1 + 0x78) & 0x40) == 0)) {
    FUN_00668620(param_1,s_Uninitialized_row_00a0c7a0);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x1000) != 0) {
    if ((char)param_2[2] == '\x03') {
      FUN_006708a0(param_2,*(int *)(param_1 + 0x124) + 1,*(undefined4 *)(param_1 + 0x144),
                   *(undefined4 *)(param_1 + 0x1b4),*(undefined2 *)(param_1 + 0x150));
    }
    else {
      if ((*(short *)(param_1 + 0x150) == 0) || ((*(uint *)(param_1 + 0x7c) & 0x2000000) == 0)) {
        iVar1 = *(int *)(param_1 + 0x124);
        iVar4 = 0;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x124);
        iVar4 = param_1 + 0x1b8;
      }
      FUN_00670ad0(param_2,iVar1 + 1,iVar4);
    }
  }
  if ((((*(uint *)(param_1 + 0x7c) & 0x40000) != 0) && ((*(uint *)(param_1 + 0x7c) & 0x80) == 0)) &&
     (((char)param_2[2] == '\x06' || ((char)param_2[2] == '\x04')))) {
    FUN_0066cd80(param_2,*(int *)(param_1 + 0x124) + 1,0);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x600000) != 0) {
    iVar4 = FUN_0066eeb0(param_1,param_2,*(int *)(param_1 + 0x124) + 1);
    if (iVar4 != 0) {
      *(undefined1 *)(param_1 + 0x260) = 1;
      if ((*(uint *)(param_1 + 0x7c) & 0x600000) == 0x400000) {
        FUN_006687b0(param_1,s_png_do_rgb_to_gray_found_nongray_00a0c778);
      }
      if ((*(uint *)(param_1 + 0x7c) & 0x600000) == 0x200000) {
        FUN_00668620(param_1,s_png_do_rgb_to_gray_found_nongray_00a0c778);
      }
    }
  }
  if (((*(uint *)(param_1 + 0x7c) & 0x4000) != 0) && ((*(uint *)(param_1 + 0x74) & 0x800) == 0)) {
    FUN_0066ed50(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(byte *)(param_1 + 0x7c) & 0x80) != 0) {
    FUN_0066f350(param_2,*(int *)(param_1 + 0x124) + 1,param_1);
  }
  uVar2 = *(uint *)(param_1 + 0x7c);
  if (((((uVar2 & 0x2000) != 0) && ((uVar2 & 0x600000) == 0)) &&
      (((uVar2 & 0x80) == 0 ||
       ((*(short *)(param_1 + 0x150) == 0 && ((*(byte *)(param_1 + 0x157) & 4) == 0)))))) &&
     (*(char *)(param_1 + 0x157) != '\x03')) {
    FUN_006703d0(param_2,*(int *)(param_1 + 0x124) + 1,param_1);
  }
  if ((((*(uint *)(param_1 + 0x7c) & 0x40000) != 0) && ((*(uint *)(param_1 + 0x7c) & 0x80) != 0)) &&
     (((char)param_2[2] == '\x06' || ((char)param_2[2] == '\x04')))) {
    FUN_0066cd80(param_2,*(int *)(param_1 + 0x124) + 1,0);
  }
  if (((*(uint *)(param_1 + 0x7c) & 0x800000) != 0) && ((*(byte *)(param_2 + 2) & 4) != 0)) {
    FUN_006707d0(param_2,*(int *)(param_1 + 0x124) + 1,param_1);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x4000000) != 0) {
    FUN_0066e860(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x400) != 0) {
    FUN_0066e8d0(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(byte *)(param_1 + 0x7c) & 0x40) != 0) {
    FUN_00670f30(param_2,*(int *)(param_1 + 0x124) + 1,*(undefined4 *)(param_1 + 0x208),
                 *(undefined4 *)(param_1 + 0x20c));
    if (param_2[1] == 0) {
      FUN_00668620(param_1,s_png_do_quantize_returned_rowbyte_00a0c754);
    }
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x200) != 0) {
    FUN_00670ee0(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if (((*(uint *)(param_1 + 0x7c) & 0x4000) != 0) && ((*(uint *)(param_1 + 0x74) & 0x800) != 0)) {
    FUN_0066ed50(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(byte *)(param_1 + 0x7c) & 0x20) != 0) {
    FUN_0066cc70(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x80000) != 0) {
    FUN_0066ea20(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(byte *)(param_1 + 0x7c) & 8) != 0) {
    FUN_0066e670(param_2,*(int *)(param_1 + 0x124) + 1,param_1 + 0x1ad);
  }
  if ((*(byte *)(param_1 + 0x7c) & 4) != 0) {
    FUN_0066e540(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if (((char)param_2[2] == '\x03') && (-1 < *(int *)(param_1 + 0x14c))) {
    FUN_0066cfb0(param_1,param_2);
  }
  if ((*(byte *)(param_1 + 0x7c) & 1) != 0) {
    FUN_0066cee0(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x10000) != 0) {
    FUN_0066cd30(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x8000) != 0) {
    FUN_0066eaf0(param_2,*(int *)(param_1 + 0x124) + 1,*(undefined2 *)(param_1 + 0x160),
                 *(undefined4 *)(param_1 + 0x78));
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x20000) != 0) {
    FUN_0066e920(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(byte *)(param_1 + 0x7c) & 0x10) != 0) {
    FUN_0066cd00(param_2,*(int *)(param_1 + 0x124) + 1);
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x100000) != 0) {
    if (*(code **)(param_1 + 100) != (code *)0x0) {
      (**(code **)(param_1 + 100))(param_1,param_2,*(int *)(param_1 + 0x124) + 1);
    }
    if (*(char *)(param_1 + 0x70) != '\0') {
      *(char *)((int)param_2 + 9) = *(char *)(param_1 + 0x70);
    }
    if (*(char *)(param_1 + 0x71) != '\0') {
      *(char *)((int)param_2 + 10) = *(char *)(param_1 + 0x71);
    }
    bVar3 = *(char *)((int)param_2 + 10) * *(char *)((int)param_2 + 9);
    *(byte *)((int)param_2 + 0xb) = bVar3;
    if (7 < bVar3) {
      param_2[1] = (uint)(bVar3 >> 3) * *param_2;
      return;
    }
    param_2[1] = (uint)bVar3 * *param_2 + 7 >> 3;
  }
  return;
}

