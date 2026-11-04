
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __handle_exc
   
   Library: Visual Studio 2003 Release */

bool __handle_exc(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  uint uVar2;
  bool bVar3;
  float10 fVar4;
  undefined8 local_14;
  int local_c;
  uint local_8;
  
  uVar2 = param_1 & 0x1f;
  local_8 = uVar2;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_0050c8b9(1);
    uVar2 = param_1 & 0x17;
    goto LAB_0050c536;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_0050c8b9(4);
    uVar2 = param_1 & 0x1b;
    goto LAB_0050c536;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar3 = (param_1 & 0x10) != 0;
      if (*param_2 == _DAT_007d0a60) {
        bVar3 = true;
      }
      else {
        fVar4 = (float10)__decomp(*param_2,&local_c);
        dVar1 = (double)fVar4;
        local_c = local_c + -0x600;
        if (local_c < -0x432) {
          local_14 = dVar1 * _DAT_007d0a60;
          bVar3 = true;
        }
        else {
          local_14 = (double)((ulonglong)dVar1 & 0xfffffffffffff | 0x10000000000000);
          if (local_c < -0x3fd) {
            local_c = -0x3fd - local_c;
            do {
              if ((((ulonglong)local_14 & 1) != 0) && (!bVar3)) {
                bVar3 = true;
              }
              uVar2 = (uint)local_14 >> 1;
              if (((ulonglong)local_14 & 0x100000000) != 0) {
                local_14._3_1_ = (byte)((ulonglong)local_14 >> 0x18) >> 1;
                local_14._0_3_ = (undefined3)uVar2;
                local_14._0_4_ = CONCAT13(local_14._3_1_,(undefined3)local_14) | 0x80000000;
                uVar2 = (uint)local_14;
              }
              local_14._0_4_ = uVar2;
              local_14 = (double)CONCAT44(local_14._4_4_ >> 1,(uint)local_14);
              local_c = local_c + -1;
            } while (local_c != 0);
          }
          if (dVar1 < _DAT_007d0a60) {
            local_14 = -local_14;
          }
        }
        *param_2 = local_14;
      }
      if (bVar3) {
        FUN_0050c8b9(0x10);
      }
      uVar2 = local_8 & 0xfffffffd;
      local_8 = uVar2;
    }
    goto LAB_0050c536;
  }
  FUN_0050c8b9(8);
  uVar2 = param_3 & 0xc00;
  dVar1 = _DAT_0084c268;
  if (uVar2 == 0) {
    if (*param_2 <= _DAT_007d0a60) {
      dVar1 = -_DAT_0084c268;
    }
LAB_0050c452:
    *param_2 = dVar1;
  }
  else {
    if (uVar2 == 0x400) {
      if (*param_2 <= _DAT_007d0a60) {
        dVar1 = -_DAT_0084c268;
      }
      else {
        dVar1 = _DAT_0084c278;
      }
      goto LAB_0050c452;
    }
    if (uVar2 == 0x800) {
      if (*param_2 <= _DAT_007d0a60) {
        dVar1 = -_DAT_0084c278;
      }
      goto LAB_0050c452;
    }
    if (uVar2 == 0xc00) {
      dVar1 = _DAT_0084c278;
      if (*param_2 <= _DAT_007d0a60) {
        dVar1 = -_DAT_0084c278;
      }
      goto LAB_0050c452;
    }
  }
  uVar2 = param_1 & 0x1e;
LAB_0050c536:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_0050c8b9(0x20);
    uVar2 = uVar2 & 0xffffffef;
  }
  return uVar2 == 0;
}

