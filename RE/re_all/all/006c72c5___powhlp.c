
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __powhlp
   
   Library: Visual Studio 2003 Release */

undefined4 __powhlp(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined4 uVar4;
  
  dVar1 = (double)CONCAT44(param_2,param_1);
  uVar4 = 0;
  if (dVar1 < _DAT_007d0a60) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_0084c268;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) goto LAB_006c7370;
    if (_DAT_00802e18 < dVar1) goto LAB_006c7420;
    if (_DAT_00802e18 <= dVar1) goto LAB_006c7323;
  }
  else {
    if ((param_3._4_4_ == -0x100000) && (param_3._0_4_ == 0)) {
      if (_DAT_00802e18 < dVar1) {
        dVar2 = 0.0;
        goto LAB_006c7420;
      }
      if (dVar1 < _DAT_00802e18) goto LAB_006c7420;
LAB_006c7323:
      uVar4 = 1;
      dVar2 = _DAT_0084c270;
      goto LAB_006c7420;
    }
LAB_006c7370:
    if (param_2 != 0x7ff00000) {
      if (param_2 != -0x100000) {
        return 0;
      }
      if (param_1 != 0) {
        return 0;
      }
      iVar3 = __d_inttype(param_3);
      if (param_3 <= _DAT_007d0a60) {
        if (_DAT_007d0a60 <= param_3) {
          dVar2 = 1.0;
        }
        else if (iVar3 == 1) {
          dVar2 = _DAT_0084c288;
        }
        else {
          dVar2 = 0.0;
        }
      }
      else {
        dVar2 = _DAT_0084c268;
        if (iVar3 == 1) {
          dVar2 = -_DAT_0084c268;
        }
      }
      goto LAB_006c7420;
    }
    if (param_1 != 0) {
      return 0;
    }
    if (_DAT_007d0a60 < param_3) goto LAB_006c7420;
    if (_DAT_007d0a60 <= param_3) {
      dVar2 = 1.0;
      goto LAB_006c7420;
    }
  }
  dVar2 = 0.0;
LAB_006c7420:
  *param_4 = dVar2;
  return uVar4;
}

