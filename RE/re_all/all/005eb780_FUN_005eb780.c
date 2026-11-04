
void FUN_005eb780(int param_1)

{
  int iVar1;
  double *unaff_EDI;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  undefined1 local_68 [100];
  
  iVar1 = *(int *)(DAT_00ef1b8c + 8);
  if (DAT_00a380c4 == 0) {
    *(undefined4 *)(iVar1 + 0xb0) = *(undefined4 *)unaff_EDI;
    *(undefined4 *)(iVar1 + 0xb4) = *(undefined4 *)((int)unaff_EDI + 4);
    *(undefined4 *)(iVar1 + 0xb8) = *(undefined4 *)(unaff_EDI + 1);
    *(undefined4 *)(iVar1 + 0xbc) = *(undefined4 *)((int)unaff_EDI + 0xc);
    *(undefined4 *)(iVar1 + 0xc0) = *(undefined4 *)(unaff_EDI + 2);
    *(undefined4 *)(iVar1 + 0xc4) = *(undefined4 *)((int)unaff_EDI + 0x14);
    *(undefined4 *)(iVar1 + 200) = *(undefined4 *)(unaff_EDI + 3);
    *(undefined4 *)(iVar1 + 0xcc) = *(undefined4 *)((int)unaff_EDI + 0x1c);
    *(undefined4 *)(iVar1 + 0xd0) = *(undefined4 *)(unaff_EDI + 4);
    *(undefined4 *)(iVar1 + 0xd4) = *(undefined4 *)((int)unaff_EDI + 0x24);
    *(undefined4 *)(iVar1 + 0xd8) = *(undefined4 *)(unaff_EDI + 5);
    *(undefined4 *)(iVar1 + 0xdc) = *(undefined4 *)((int)unaff_EDI + 0x2c);
    *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
    return;
  }
  if (param_1 == 0) {
    FUN_00582890(local_68,&DAT_00a38358);
    FUN_00582380(&local_c8);
    *(float *)(iVar1 + 0xb0) = (float)local_c8;
    *(float *)(iVar1 + 0xb4) = (float)local_c0;
    *(float *)(iVar1 + 0xb8) = (float)local_b8;
    *(float *)(iVar1 + 0xbc) = (float)local_b0;
    *(float *)(iVar1 + 0xc0) = (float)local_a8;
    *(float *)(iVar1 + 0xc4) = (float)local_a0;
    *(float *)(iVar1 + 200) = (float)local_98;
    *(float *)(iVar1 + 0xcc) = (float)local_90;
    *(float *)(iVar1 + 0xd0) = (float)local_88;
    *(float *)(iVar1 + 0xd4) = (float)local_80;
    *(float *)(iVar1 + 0xd8) = (float)local_78;
    *(float *)(iVar1 + 0xdc) = (float)local_70;
    FUN_005b9490(&DAT_00a054c0);
    *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
    return;
  }
  *(float *)(iVar1 + 0xb0) = (float)*unaff_EDI;
  *(float *)(iVar1 + 0xb4) = (float)unaff_EDI[1];
  *(float *)(iVar1 + 0xb8) = (float)unaff_EDI[2];
  *(float *)(iVar1 + 0xbc) = (float)unaff_EDI[3];
  *(float *)(iVar1 + 0xc0) = (float)unaff_EDI[4];
  *(float *)(iVar1 + 0xc4) = (float)unaff_EDI[5];
  *(float *)(iVar1 + 200) = (float)unaff_EDI[6];
  *(float *)(iVar1 + 0xcc) = (float)unaff_EDI[7];
  *(float *)(iVar1 + 0xd0) = (float)unaff_EDI[8];
  *(float *)(iVar1 + 0xd4) = (float)unaff_EDI[9];
  *(float *)(iVar1 + 0xd8) = (float)unaff_EDI[10];
  *(float *)(iVar1 + 0xdc) = (float)unaff_EDI[0xb];
  *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
  return;
}

