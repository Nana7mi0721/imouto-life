
undefined4 FUN_0052f260(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  uVar10 = *(uint *)(param_2 + 0x93184) & 1;
  if (uVar10 != 0) {
    *(short *)(param_2 + 0x9316a) =
         *(short *)(param_2 + 0x9316a) + *(short *)(param_2 + 0x93188) * 2;
  }
  uVar2 = (short)((int)(*(ushort *)(param_2 + 0x9316a) + 7) >> 3) * 8;
  *(ushort *)(param_2 + 0x9316a) = uVar2;
  if (uVar10 != 0) {
    *(short *)(param_2 + 0x93164) =
         *(short *)(param_2 + 0x93164) + *(short *)(param_2 + 0x93188) * 2;
  }
  uVar4 = (short)((*(ushort *)(param_2 + 0x93164) + 1) / 2) * 2;
  *(ushort *)(param_2 + 0x93164) = uVar4;
  if (uVar2 < uVar4) {
    *(ushort *)(param_2 + 0x9316a) = uVar4;
  }
  if ((DAT_00a37d78 == 0) || (*param_1 != 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  *(int *)(param_2 + 0x93628) = iVar5;
  if (((iVar5 == 0) || ((*(uint *)(param_2 + 0x93184) & 2) == 0)) || (uVar7 = 0x20, param_1[1] != 0)
     ) {
    uVar7 = 0x10;
  }
  *(undefined4 *)(param_2 + 0x935fc) = uVar7;
  *(int *)(param_2 + 0x93600) = param_1[3];
  *(undefined4 *)(param_2 + 0x93614) = 0;
  *(undefined4 *)(param_2 + 0x93618) = 0;
  *(undefined4 *)(param_2 + 0x9361c) = 0;
  *(undefined4 *)(param_2 + 0x93620) = 0;
  *(undefined4 *)(param_2 + 0x93624) = 0;
  if (iVar5 == 1) {
    puVar1 = (undefined4 *)(param_2 + 0x931bc);
    do {
      iVar8 = DAT_00a37e64 * DAT_00a37e60;
      *(undefined4 *)(param_2 + 0x9318c) = 8;
      *(undefined4 *)(param_2 + 0x93190) = 8;
      iVar5 = (int)(8 / (ulonglong)(longlong)(int)(uint)*(ushort *)(param_2 + 0x9316a));
      uVar10 = iVar5 * iVar5;
      if (uVar10 < 0x7e8) {
        do {
          iVar5 = param_1[2];
          if (iVar5 < 1) {
            if ((iVar8 * 0x55) / 100 <= *(int *)(param_2 + 0x93190) * *(int *)(param_2 + 0x9318c)) {
              bVar12 = SBORROW4(uVar10,10);
              iVar5 = uVar10 - 10;
              goto LAB_0052f3d4;
            }
          }
          else {
            bVar12 = SBORROW4(uVar10,iVar5);
            iVar5 = uVar10 - iVar5;
LAB_0052f3d4:
            if (bVar12 == iVar5 < 0) goto LAB_0052f436;
          }
          iVar5 = *(int *)(param_2 + 0x9318c);
          if ((DAT_00a37db4 <= iVar5) && (DAT_00a37db4 <= *(int *)(param_2 + 0x93190)))
          goto LAB_0052f436;
          if (*(int *)(param_2 + 0x93190) < iVar5) {
            *(int *)(param_2 + 0x93190) = *(int *)(param_2 + 0x93190) * 2;
          }
          else {
            *(int *)(param_2 + 0x9318c) = iVar5 * 2;
          }
          uVar10 = (*(int *)(param_2 + 0x9318c) / (int)(uint)*(ushort *)(param_2 + 0x9316a)) *
                   (*(int *)(param_2 + 0x93190) / (int)(uint)*(ushort *)(param_2 + 0x9316a));
        } while ((int)uVar10 < 0x7e8);
      }
      uVar10 = 0x7e8;
LAB_0052f436:
      *(uint *)(param_2 + 0x90d88) = uVar10;
      *(int *)(param_2 + 0x93194) =
           *(int *)(param_2 + 0x93190) / (int)(uint)*(ushort *)(param_2 + 0x9316a);
      uVar10 = *(uint *)(param_2 + 0x93184);
      bVar12 = (uVar10 & 2) == 0;
      if (DAT_00a37d9c == 0) {
        puVar6 = (undefined4 *)FUN_00526340(!bVar12,bVar12,*(int *)(param_2 + 0x935fc) != 0x10,0);
        puVar11 = puVar1;
        for (iVar5 = 0x10a; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar11 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar11 = puVar11 + 1;
        }
      }
      else {
        FUN_00544440(puVar1);
        if (((*(byte *)(param_2 + 0x93184) & 2) == 0) ||
           (((*(int *)(param_2 + 0x38) != 0 && (*(int *)(param_2 + 0x50) != 7)) &&
            (*(int *)(param_2 + 0x50) != 8)))) {
          iVar5 = 0;
          *(undefined4 *)(param_2 + 0x931e0) = 0xf;
          puVar9 = (undefined1 *)(param_2 + 0x931e5);
          if (*(int *)(param_2 + 0x93600) == 0) {
            do {
              puVar9[1] = 0xff;
              *puVar9 = 0xff;
              puVar9[-1] = 0xff;
              puVar9[2] = (char)(iVar5 / 0xf);
              iVar5 = iVar5 + 0xff;
              puVar9 = puVar9 + 4;
            } while (iVar5 < 0xff0);
          }
          else {
            do {
              uVar3 = (undefined1)(iVar5 / 0xf);
              puVar9[1] = uVar3;
              *puVar9 = uVar3;
              puVar9[-1] = uVar3;
              puVar9[2] = uVar3;
              iVar5 = iVar5 + 0xff;
              puVar9 = puVar9 + 4;
            } while (iVar5 < 0xff0);
          }
        }
        else {
          *(undefined4 *)(param_2 + 0x931e0) = 0xff;
          if (*(int *)(param_2 + 0x93600) == 0) {
            iVar5 = 0;
            puVar9 = (undefined1 *)(param_2 + 0x931e5);
            do {
              puVar9[2] = (char)iVar5;
              puVar9[1] = 0xff;
              *puVar9 = 0xff;
              puVar9[-1] = 0xff;
              iVar5 = iVar5 + 1;
              puVar9 = puVar9 + 4;
            } while (iVar5 < 0x100);
          }
          else {
            iVar5 = 0;
            puVar9 = (undefined1 *)(param_2 + 0x931e5);
            do {
              uVar3 = (undefined1)iVar5;
              puVar9[1] = uVar3;
              *puVar9 = uVar3;
              puVar9[-1] = uVar3;
              puVar9[2] = uVar3;
              iVar5 = iVar5 + 1;
              puVar9 = puVar9 + 4;
            } while (iVar5 < 0x100);
          }
        }
      }
      *(undefined4 *)(param_2 + 0x935f4) = 0;
      *(undefined4 *)(param_2 + 0x935f8) = 0;
      *(uint *)(param_2 + 0x935e4) = (((uVar10 & 1) != 0) + 1) * *(int *)(param_2 + 0x9318c);
      iVar5 = (uint)*(byte *)(param_2 + 0x931c0) * *(int *)(param_2 + 0x935e4);
      *(int *)(param_2 + 0x935e8) = *(int *)(param_2 + 0x93190);
      *(int *)(param_2 + 0x935ec) = iVar5;
      iVar5 = FUN_0056e030(*(int *)(param_2 + 0x93190) * iVar5,
                           "..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x15a3);
      *(int *)(param_2 + 0x935f0) = iVar5;
      if (iVar5 == 0) {
        FUN_0056bb10(&DAT_007d5b98);
        return 0xffffffff;
      }
      if (DAT_00a37d9c == 0) {
        if (*(int *)(param_2 + 0x93600) == 0) {
          uVar14 = 0xff;
          uVar13 = 0xff;
          uVar7 = 0xff;
        }
        else {
          uVar14 = 0;
          uVar13 = 0;
          uVar7 = 0;
        }
      }
      else {
        uVar14 = 0;
        uVar13 = 0;
        uVar7 = 0;
      }
      FUN_005492e0(puVar1,uVar7,uVar13,uVar14,0);
      *(undefined4 *)(param_2 + 0x931b8) = 1;
      iVar5 = FUN_0052eeb0(param_2,param_3);
      if (-1 < iVar5) goto LAB_0052f7b1;
      FUN_0056bb10(&DAT_007d5bd4);
      *(undefined4 *)(param_2 + 0x93628) = 0;
    } while (*(int *)(param_2 + 0x93628) == 1);
  }
  iVar5 = 0;
  switch(*(undefined4 *)(param_2 + 0x93184)) {
  case 0:
    iVar5 = 1;
    break;
  case 1:
  case 2:
  case 3:
  case 0x12:
  case 0x13:
  case 0x22:
  case 0x23:
    iVar5 = 8;
  }
  iVar8 = param_1[2];
  *(int *)(param_2 + 0x90d88) = iVar8;
  if ((iVar8 == 0) &&
     (iVar8 = (int)(0x50000 /
                   (longlong)
                   (int)((uint)*(ushort *)(param_2 + 0x9316a) * (uint)*(ushort *)(param_2 + 0x9316a)
                        )), *(int *)(param_2 + 0x90d88) = iVar8, iVar8 < 0x14)) {
    *(undefined4 *)(param_2 + 0x90d88) = 0x14;
  }
  if (0x7e8 < *(int *)(param_2 + 0x90d88)) {
    *(undefined4 *)(param_2 + 0x90d88) = 0x7e8;
  }
  uVar10 = (uint)*(ushort *)(param_2 + 0x9316a);
  iVar8 = *(int *)(param_2 + 0x90d88) * uVar10;
  *(int *)(param_2 + 0x93190) = iVar8;
  iVar8 = iVar8 / (int)uVar10;
  *(uint *)(param_2 + 0x9318c) = uVar10;
  *(int *)(param_2 + 0x90d94) = iVar5;
  *(int *)(param_2 + 0x90d88) = iVar8;
  *(int *)(param_2 + 0x93194) = iVar8;
  iVar5 = (int)(uVar10 * iVar5 + 7) >> 3;
  *(int *)(param_2 + 0x90d90) = iVar5;
  iVar5 = FUN_0056e030(*(int *)(param_2 + 0x93190) * iVar5,
                       "..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x15f5);
  *(int *)(param_2 + 0x90d8c) = iVar5;
  if (iVar5 == 0) {
    FUN_0056bb10(&DAT_007d5b38);
    return 0xffffffff;
  }
  iVar5 = FUN_0052eeb0(param_2,param_3);
  if (iVar5 < 0) {
    FUN_0056bb10(&DAT_007d5b08);
    return 0xffffffff;
  }
LAB_0052f7b1:
  iVar5 = *(ushort *)(param_2 + 0x9316a) + 4;
  iVar5 = iVar5 * iVar5;
  *(int *)(param_2 + 0x9319c) = iVar5;
  iVar5 = FUN_0056e030(iVar5,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x1606);
  *(int *)(param_2 + 0x93198) = iVar5;
  if (iVar5 == 0) {
    FUN_0056bb10(&DAT_007d5ad8);
    return 0xffffffff;
  }
  FUN_0052ee10(param_2,param_3);
  return 0;
}

