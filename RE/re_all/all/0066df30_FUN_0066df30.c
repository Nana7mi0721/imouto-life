
void FUN_0066df30(int param_1,int *param_2)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  if ((*(uint *)(param_1 + 0x7c) & 0x1000) != 0) {
    if (*(byte *)((int)param_2 + 0x19) == 3) {
      sVar1 = *(short *)(param_1 + 0x150);
      *(undefined1 *)(param_2 + 6) = 8;
      *(undefined2 *)((int)param_2 + 0x16) = 0;
      *(byte *)((int)param_2 + 0x19) = (-(sVar1 != 0) & 4U) + 2;
      if (*(int *)(param_1 + 0x144) == 0) {
        FUN_00668620(param_1,s_Palette_is_NULL_in_indexed_image_00a0c730);
      }
    }
    else {
      if ((*(short *)(param_1 + 0x150) != 0) && ((*(uint *)(param_1 + 0x7c) & 0x2000000) != 0)) {
        *(byte *)((int)param_2 + 0x19) = *(byte *)((int)param_2 + 0x19) | 4;
      }
      if (*(byte *)(param_2 + 6) < 8) {
        *(undefined1 *)(param_2 + 6) = 8;
      }
      *(undefined2 *)((int)param_2 + 0x16) = 0;
    }
  }
  if ((*(byte *)(param_1 + 0x7c) & 0x80) != 0) {
    *(undefined4 *)((int)param_2 + 0xaa) = *(undefined4 *)(param_1 + 0x168);
    *(undefined4 *)((int)param_2 + 0xae) = *(undefined4 *)(param_1 + 0x16c);
    *(undefined2 *)((int)param_2 + 0xb2) = *(undefined2 *)(param_1 + 0x170);
  }
  param_2[10] = *(int *)(param_1 + 0x2dc);
  if ((char)param_2[6] == '\x10') {
    if ((*(uint *)(param_1 + 0x7c) & 0x4000000) != 0) {
      *(undefined1 *)(param_2 + 6) = 8;
    }
    if ((*(uint *)(param_1 + 0x7c) & 0x400) != 0) {
      *(undefined1 *)(param_2 + 6) = 8;
    }
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x4000) != 0) {
    *(byte *)((int)param_2 + 0x19) = *(byte *)((int)param_2 + 0x19) | 2;
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x600000) != 0) {
    *(byte *)((int)param_2 + 0x19) = *(byte *)((int)param_2 + 0x19) & 0xfd;
  }
  if ((((*(byte *)(param_1 + 0x7c) & 0x40) != 0) &&
      (((*(char *)((int)param_2 + 0x19) == '\x02' || (*(char *)((int)param_2 + 0x19) == '\x06')) &&
       (*(int *)(param_1 + 0x208) != 0)))) && ((char)param_2[6] == '\b')) {
    *(undefined1 *)((int)param_2 + 0x19) = 3;
  }
  if ((((*(uint *)(param_1 + 0x7c) & 0x200) != 0) && ((char)param_2[6] == '\b')) &&
     (*(char *)((int)param_2 + 0x19) != '\x03')) {
    *(undefined1 *)(param_2 + 6) = 0x10;
  }
  if (((*(byte *)(param_1 + 0x7c) & 4) != 0) && (*(byte *)(param_2 + 6) < 8)) {
    *(undefined1 *)(param_2 + 6) = 8;
  }
  bVar2 = *(byte *)((int)param_2 + 0x19);
  if ((bVar2 == 3) || ((bVar2 & 2) == 0)) {
    *(undefined1 *)((int)param_2 + 0x1d) = 1;
  }
  else {
    *(undefined1 *)((int)param_2 + 0x1d) = 3;
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x40000) != 0) {
    *(undefined2 *)((int)param_2 + 0x16) = 0;
    *(byte *)((int)param_2 + 0x19) = bVar2 & 0xfb;
  }
  bVar2 = *(byte *)((int)param_2 + 0x19);
  if ((bVar2 & 4) != 0) {
    *(char *)((int)param_2 + 0x1d) = *(char *)((int)param_2 + 0x1d) + '\x01';
  }
  if (((*(uint *)(param_1 + 0x7c) & 0x8000) != 0) &&
     (((bVar2 == 2 || (bVar2 == 0)) &&
      (*(char *)((int)param_2 + 0x1d) = *(char *)((int)param_2 + 0x1d) + '\x01',
      (*(uint *)(param_1 + 0x7c) & 0x1000000) != 0)))) {
    *(byte *)((int)param_2 + 0x19) = bVar2 | 4;
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x100000) != 0) {
    if (*(byte *)(param_2 + 6) < *(byte *)(param_1 + 0x70)) {
      *(byte *)(param_2 + 6) = *(byte *)(param_1 + 0x70);
    }
    if (*(byte *)((int)param_2 + 0x1d) < *(byte *)(param_1 + 0x71)) {
      *(byte *)((int)param_2 + 0x1d) = *(byte *)(param_1 + 0x71);
    }
  }
  bVar2 = (char)param_2[6] * *(char *)((int)param_2 + 0x1d);
  *(byte *)((int)param_2 + 0x1e) = bVar2;
  if (bVar2 < 8) {
    uVar4 = (uint)bVar2 * *param_2 + 7 >> 3;
    param_2[3] = uVar4;
    *(uint *)(param_1 + 0x138) = uVar4;
    return;
  }
  iVar3 = (uint)(bVar2 >> 3) * *param_2;
  param_2[3] = iVar3;
  *(int *)(param_1 + 0x138) = iVar3;
  return;
}

