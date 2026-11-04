
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __modf_default
   
   Library: Visual Studio 2003 Release */

float10 __modf_default(double param_1,double *param_2)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 local_c;
  
  uVar2 = __ctrlfp(0,0);
  __ctrlfp(DAT_00a0f638,0xffff);
  uVar5 = SUB84(param_1,0);
  uVar6 = (undefined4)((ulonglong)param_1 >> 0x20);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    *param_2 = _DAT_0084c270;
    iVar3 = __sptype(uVar5,uVar6);
    if (0 < iVar3) {
      if (iVar3 < 3) {
        *param_2 = param_1;
        local_c = __copysign(0.0,param_1);
        __ctrlfp(uVar2,0xffff);
        goto LAB_006c8bca;
      }
      if (iVar3 == 3) {
        *param_2 = param_1;
        fVar4 = (float10)__handle_qnan1(0x1c,uVar5,uVar6,uVar2);
        return fVar4;
      }
    }
    param_1 = param_1 + _DAT_00802e18;
    *param_2 = param_1;
    fVar4 = (float10)__except1(8,0x1c,uVar5,uVar6,param_1,uVar2);
  }
  else {
    fVar4 = (float10)__frnd(uVar5,uVar6);
    *param_2 = (double)fVar4;
    dVar1 = param_1 - (double)fVar4;
    local_c = dVar1;
    if (dVar1 == _DAT_007d0a60) {
      local_c._6_2_ = (ushort)((ulonglong)dVar1 >> 0x30);
      local_c = (double)CONCAT26(local_c._6_2_ | param_1._6_2_ & 0x8000,SUB86(dVar1,0));
    }
    __ctrlfp(uVar2,0xffff);
LAB_006c8bca:
    fVar4 = (float10)local_c;
  }
  return fVar4;
}

