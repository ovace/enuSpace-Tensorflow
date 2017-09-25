#pragma once


#ifndef _GLOBAL_HEADER_
#define _GLOBAL_HEADER_

#include <cstdio>
#include <functional>
#include <string>
#include <vector>

#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/cc/ops/random_ops.h"
#include "tensorflow/core/framework/graph.pb.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/graph/default_device.h"
#include "tensorflow/core/graph/graph_def_builder.h"
#include "tensorflow/core/lib/core/threadpool.h"
#include "tensorflow/core/lib/strings/stringprintf.h"
#include "tensorflow/core/platform/init_main.h"
#include "tensorflow/core/platform/logging.h"
#include "tensorflow/core/platform/types.h"
#include "tensorflow/core/public/session.h"
#include "tensorflow/cc/client/client_session.h"

#include "include/json/json.h"

#define SYMBOL_NONE														-1
#define SYMBOL_BATCHTOSPACE 											1
#define SYMBOL_BATCHTOSPACEND 											2
#define SYMBOL_BITCAST 													3
#define SYMBOL_BROADCASTDYNAMICSHAPE 									4
#define SYMBOL_CHECKNUMERICS 		5
#define SYMBOL_CONCAT 		6
#define SYMBOL_DEPTHTOSPACE 		7
#define SYMBOL_DEQUANTIZE 		8
#define SYMBOL_DIAG 		9
#define SYMBOL_DIAGPART 		10
#define SYMBOL_EDITDISTANCE 		11
#define SYMBOL_EXPANDDIMS 		12
#define SYMBOL_EXTRACTIMAGEPATCHES 		13
#define SYMBOL_FAKEQUANTWITHMINMAXARGS 		14
#define SYMBOL_FAKEQUANTWITHMINMAXARGSGRADIENT 		15
#define SYMBOL_FAKEQUANTWITHMINMAXVARS 		16
#define SYMBOL_FAKEQUANTWITHMINMAXVARSGRADIENT 		17
#define SYMBOL_FAKEQUANTWITHMINMAXVARSPERCHANNEL 		18
#define SYMBOL_FAKEQUANTWITHMINMAXVARSPERCHANNELGRADIENT 		19
#define SYMBOL_FILL 		20
#define SYMBOL_GATHER 		21
#define SYMBOL_GATHERND 		22
#define SYMBOL_IDENTITY 		23
#define SYMBOL_IMMUTABLECONST 		24
#define SYMBOL_INVERTPERMUTATION 		25
#define SYMBOL_MATRIXBANDPART 		26
#define SYMBOL_MATRIXDIAG 		27
#define SYMBOL_MATRIXDIAGPART 		28
#define SYMBOL_MATRIXSETDIAG 		29
#define SYMBOL_MIRRORPAD 		30
#define SYMBOL_ONEHOT 		31
#define SYMBOL_ONESLIKE 		32
#define SYMBOL_PAD 		33
#define SYMBOL_PARALLELCONCAT 		34
#define SYMBOL_PLACEHOLDER 		35
//#define SYMBOL_PLACEHOLDERV2 		36
#define SYMBOL_PLACEHOLDERWITHDEFAULT 		37
#define SYMBOL_PREVENTGRADIENT 		38
#define SYMBOL_QUANTIZEANDDEQUANTIZEV2 		39
#define SYMBOL_QUANTIZEV2 		40
#define SYMBOL_QUANTIZEDCONCAT 		41
#define SYMBOL_QUANTIZEDINSTANCENORM 		42
#define SYMBOL_QUANTIZEDRESHAPE 		43
#define SYMBOL_RANK 		44
#define SYMBOL_RESHAPE 		45
#define SYMBOL_RESOURCESTRIDEDSLICEASSIGN 		46
#define SYMBOL_REVERSE 		47
#define SYMBOL_REVERSESEQUENCE 		48
#define SYMBOL_SCATTERND 		49
#define SYMBOL_SETDIFF1D 		50
#define SYMBOL_SHAPE 		51
#define SYMBOL_SHAPEN 		52
#define SYMBOL_SIZE 		53
#define SYMBOL_SLICE 		54
#define SYMBOL_SPACETOBATCH 		55
#define SYMBOL_SPACETOBATCHND 		56
#define SYMBOL_SPACETODEPTH 		57
#define SYMBOL_SPLIT 		58
#define SYMBOL_SPLITV 		59
#define SYMBOL_SQUEEZE 		60
#define SYMBOL_STACK 		61
#define SYMBOL_STOPGRADIENT 		62
#define SYMBOL_STRIDEDSLICE 		63
#define SYMBOL_STRIDEDSLICEASSIGN 		64
#define SYMBOL_STRIDEDSLICEGRAD 		65
#define SYMBOL_TILE 		66
#define SYMBOL_TRANSPOSE 		67
#define SYMBOL_UNIQUE 		68
#define SYMBOL_UNIQUEWITHCOUNTS 		69
#define SYMBOL_UNSTACK 		70
#define SYMBOL_WHERE 		71
#define SYMBOL_ZEROSLIKE 		72
#define SYMBOL_ALLCANDIDATESAMPLER 		73
#define SYMBOL_COMPUTEACCIDENTALHITS 		74
#define SYMBOL_FIXEDUNIGRAMCANDIDATESAMPLER 		75
#define SYMBOL_LEARNEDUNIGRAMCANDIDATESAMPLER 		76
#define SYMBOL_LOGUNIFORMCANDIDATESAMPLER 		77
#define SYMBOL_UNIFORMCANDIDATESAMPLER 		78
#define SYMBOL_ABORT 		79
#define SYMBOL_CONTROLTRIGGER 		80
#define SYMBOL_LOOPCOND 		81
#define SYMBOL_MERGE 		82
#define SYMBOL_NEXTITERATION 		83
#define SYMBOL_REFNEXTITERATION 		84
#define SYMBOL_REFSELECT 		85
#define SYMBOL_REFSWITCH 		86
#define SYMBOL_SWITCH 		87
#define SYMBOL_CLIENTSESSION 		88
#define SYMBOL_INPUT 		89
#define SYMBOL_INPUT_INITIALIZER 		90
#define SYMBOL_INPUTLIST 		91
#define SYMBOL_OPERATION 		92
#define SYMBOL_OUTPUT 		93
#define SYMBOL_SCOPE 		94
#define SYMBOL_STATUS 		95
#define SYMBOL_TENSOR 		96
#define SYMBOL_ACCUMULATORAPPLYGRADIENT 		97
#define SYMBOL_ACCUMULATORNUMACCUMULATED 		98
#define SYMBOL_ACCUMULATORSETGLOBALSTEP 		99
#define SYMBOL_ACCUMULATORTAKEGRADIENT 		100
#define SYMBOL_BARRIER 		101
#define SYMBOL_BARRIERCLOSE 		102
#define SYMBOL_BARRIERINCOMPLETESIZE 		103
#define SYMBOL_BARRIERINSERTMANY 		104
#define SYMBOL_BARRIERREADYSIZE 		105
#define SYMBOL_BARRIERTAKEMANY 		106
#define SYMBOL_CONDITIONALACCUMULATOR 		107
#define SYMBOL_DELETESESSIONTENSOR 		108
#define SYMBOL_DYNAMICPARTITION 		109
#define SYMBOL_DYNAMICSTITCH 		110
#define SYMBOL_FIFOQUEUE 		111
#define SYMBOL_GETSESSIONHANDLE 		112
#define SYMBOL_GETSESSIONHANDLEV2 		113
#define SYMBOL_GETSESSIONTENSOR 		114
#define SYMBOL_PADDINGFIFOQUEUE 		115
#define SYMBOL_PRIORITYQUEUE 		116
#define SYMBOL_QUEUECLOSE 		117
#define SYMBOL_QUEUEDEQUEUE 		118
#define SYMBOL_QUEUEDEQUEUEMANY 		119
#define SYMBOL_QUEUEDEQUEUEUPTO 		120
#define SYMBOL_QUEUEENQUEUE 		121
#define SYMBOL_QUEUEENQUEUEMANY 		122
#define SYMBOL_QUEUESIZE 		123
#define SYMBOL_RANDOMSHUFFLEQUEUE 		124
#define SYMBOL_RECORDINPUT 		125
#define SYMBOL_SPARSEACCUMULATORAPPLYGRADIENT 		126
#define SYMBOL_SPARSEACCUMULATORTAKEGRADIENT 		127
#define SYMBOL_SPARSECONDITIONALACCUMULATOR 		128
#define SYMBOL_STAGE 		129
#define SYMBOL_TENSORARRAY 		130
#define SYMBOL_TENSORARRAYCLOSE 		131
#define SYMBOL_TENSORARRAYCONCAT 		132
#define SYMBOL_TENSORARRAYGATHER 		133
#define SYMBOL_TENSORARRAYGRAD 		134
#define SYMBOL_TENSORARRAYREAD 		135
#define SYMBOL_TENSORARRAYSCATTER 		136
#define SYMBOL_TENSORARRAYSIZE 		137
#define SYMBOL_TENSORARRAYSPLIT 		138
#define SYMBOL_TENSORARRAYWRITE 		139
#define SYMBOL_UNSTAGE 		140
#define SYMBOL_ADJUSTCONTRAST 		141
#define SYMBOL_ADJUSTHUE 		142
#define SYMBOL_ADJUSTSATURATION 		143
#define SYMBOL_CROPANDRESIZE 		144
#define SYMBOL_CROPANDRESIZEGRADBOXES 		145
#define SYMBOL_CROPANDRESIZEGRADIMAGE 		146
#define SYMBOL_DECODEGIF 		147
#define SYMBOL_DECODEJPEG 		148
#define SYMBOL_DECODEPNG 		149
#define SYMBOL_DRAWBOUNDINGBOXES 		150
#define SYMBOL_ENCODEJPEG 		151
#define SYMBOL_ENCODEPNG 		152
#define SYMBOL_EXTRACTGLIMPSE 		153
#define SYMBOL_HSVTORGB 		154
#define SYMBOL_NONMAXSUPPRESSION 		155
#define SYMBOL_RGBTOHSV 		156
#define SYMBOL_RESIZEAREA 		157
#define SYMBOL_RESIZEBICUBIC 		158
#define SYMBOL_RESIZEBILINEAR 		159
#define SYMBOL_RESIZENEARESTNEIGHBOR 		160
#define SYMBOL_SAMPLEDISTORTEDBOUNDINGBOX 		161
#define SYMBOL_FIXEDLENGTHRECORDREADER 		162
#define SYMBOL_IDENTITYREADER 		163
#define SYMBOL_MATCHINGFILES 		164
#define SYMBOL_MERGEV2CHECKPOINTS 		165
#define SYMBOL_READFILE 		166
#define SYMBOL_READERNUMRECORDSPRODUCED 		167
#define SYMBOL_READERNUMWORKUNITSCOMPLETED 		168
#define SYMBOL_READERREAD 		169
#define SYMBOL_READERREADUPTO 		170
#define SYMBOL_READERRESET 		171
#define SYMBOL_READERRESTORESTATE 		172
#define SYMBOL_READERSERIALIZESTATE 		173
#define SYMBOL_RESTORE 		174
#define SYMBOL_RESTORESLICE 		175
#define SYMBOL_RESTOREV2 		176
#define SYMBOL_SAVE 		177
#define SYMBOL_SAVESLICES 		178
#define SYMBOL_SAVEV2 		179
#define SYMBOL_SHARDEDFILENAME 		180
#define SYMBOL_SHARDEDFILESPEC 		181
#define SYMBOL_TFRECORDREADER 		182
#define SYMBOL_TEXTLINEREADER 		183
#define SYMBOL_WHOLEFILEREADER 		184
#define SYMBOL_WRITEFILE 		185
#define SYMBOL_ASSERT 		186
#define SYMBOL_HISTOGRAMSUMMARY 		187
#define SYMBOL_MERGESUMMARY 		188
#define SYMBOL_PRINT 		189
#define SYMBOL_SCALARSUMMARY 		190
#define SYMBOL_TENSORSUMMARY 		191
#define SYMBOL_ABS 		192
#define SYMBOL_ACOS 		193
#define SYMBOL_ADD 		194
#define SYMBOL_ADDN 		195
#define SYMBOL_ALL 		196
#define SYMBOL_ANY 		197
#define SYMBOL_APPROXIMATEEQUAL 		198
#define SYMBOL_ARGMAX 		199
#define SYMBOL_ARGMIN 		200
#define SYMBOL_ASIN 		201
#define SYMBOL_ATAN 		202
#define SYMBOL_ATAN2 		203
#define SYMBOL_BATCHMATMUL 		204
#define SYMBOL_BETAINC 		205
#define SYMBOL_BINCOUNT 		206
#define SYMBOL_BUCKETIZE 		207
#define SYMBOL_CAST 		208
#define SYMBOL_CEIL 		209
#define SYMBOL_COMPLEX 		210
#define SYMBOL_COMPLEXABS 		211
#define SYMBOL_CONJ 		212
#define SYMBOL_COS 		213

#define SYMBOL_CROSS 		214
#define SYMBOL_CUMPROD 		215
#define SYMBOL_CUMSUM 		216
#define SYMBOL_DIGAMMA 		217
#define SYMBOL_DIV 		218
#define SYMBOL_EQUAL 		219
#define SYMBOL_ERF 		220
#define SYMBOL_ERFC 		221
#define SYMBOL_EXP 		222
#define SYMBOL_EXPM1 		223
#define SYMBOL_FLOOR 		224
#define SYMBOL_FLOORDIV 		225
#define SYMBOL_FLOORMOD 		226
#define SYMBOL_GREATER 		227
#define SYMBOL_GREATEREQUAL 		228
#define SYMBOL_IGAMMA 		229
#define SYMBOL_IGAMMAC 		230
#define SYMBOL_IMAG 		231

#define SYMBOL_ISINF 		232
#define SYMBOL_ISNAN 		233
#define SYMBOL_LESS 		234
#define SYMBOL_LESSEQUAL 		235
#define SYMBOL_LGAMMA 		236
#define SYMBOL_LINSPACE 		237
#define SYMBOL_LOG 		238
#define SYMBOL_LOG1P 		239
#define SYMBOL_LOGICALAND 		240
#define SYMBOL_LOGICALNOT 		241
#define SYMBOL_LOGICALOR 		242
#define SYMBOL_MATMUL 		243
#define SYMBOL_MAX 		244
#define SYMBOL_MAXIMUM 		245
#define SYMBOL_MEAN 		246
#define SYMBOL_MIN 		247
#define SYMBOL_MINIMUM 		248
#define SYMBOL_MOD 		249
#define SYMBOL_MULTIPLY 		250
#define SYMBOL_NEGATE 		251
#define SYMBOL_NOTEQUAL 		252
#define SYMBOL_POLYGAMMA 		253
#define SYMBOL_POW 		254
#define SYMBOL_PROD 		255
#define SYMBOL_QUANTIZEDOWNANDSHRINKRANGE 		256
#define SYMBOL_QUANTIZEDMATMUL 		257
#define SYMBOL_QUANTIZEDMUL 		258
#define SYMBOL_RANGE 		259
#define SYMBOL_REAL 		260
#define SYMBOL_REALDIV 		261
#define SYMBOL_RECIPROCAL 		262
#define SYMBOL_REQUANTIZATIONRANGE 		263
#define SYMBOL_REQUANTIZE 		264
#define SYMBOL_RINT 		265
#define SYMBOL_ROUND 		266
#define SYMBOL_RSQRT 		267
#define SYMBOL_SEGMENTMAX 		268
#define SYMBOL_SEGMENTMEAN 		269
#define SYMBOL_SEGMENTMIN 		270
#define SYMBOL_SEGMENTPROD 		271
#define SYMBOL_SEGMENTSUM 		272
#define SYMBOL_SIGMOID 		273
#define SYMBOL_SIGN 		274
#define SYMBOL_SIN 		275

#define SYMBOL_SPARSEMATMUL 		276
#define SYMBOL_SPARSESEGMENTMEAN 		277
#define SYMBOL_SPARSESEGMENTMEANGRAD 		278
#define SYMBOL_SPARSESEGMENTSQRTN 		279
#define SYMBOL_SPARSESEGMENTSQRTNGRAD 		280
#define SYMBOL_SPARSESEGMENTSUM 		281
#define SYMBOL_SQRT 		282
#define SYMBOL_SQUARE 		283
#define SYMBOL_SQUAREDDIFFERENCE 		284
#define SYMBOL_SUBTRACT 		285
#define SYMBOL_SUM 		286
#define SYMBOL_TAN 		287
#define SYMBOL_TANH 		288
#define SYMBOL_TRUNCATEDIV 		289
#define SYMBOL_TRUNCATEMOD 		290
#define SYMBOL_UNSORTEDSEGMENTMAX 		291
#define SYMBOL_UNSORTEDSEGMENTSUM 		292
#define SYMBOL_WHERE3 		293
#define SYMBOL_ZETA 		294
#define SYMBOL_AVGPOOL 		295
#define SYMBOL_AVGPOOL3D 		296
#define SYMBOL_AVGPOOL3DGRAD 		297
#define SYMBOL_BIASADD 		298
#define SYMBOL_BIASADDGRAD 		299
#define SYMBOL_CONV2D 		300
#define SYMBOL_CONV2DBACKPROPFILTER 		301
#define SYMBOL_CONV2DBACKPROPINPUT 		302
#define SYMBOL_CONV3D 		303
#define SYMBOL_CONV3DBACKPROPFILTERV2 		304
#define SYMBOL_CONV3DBACKPROPINPUTV2 		305
#define SYMBOL_DEPTHWISECONV2DNATIVE 		306
#define SYMBOL_DEPTHWISECONV2DNATIVEBACKPROPFILTER 		307
#define SYMBOL_DEPTHWISECONV2DNATIVEBACKPROPINPUT 		308
#define SYMBOL_DILATION2D 		309
#define SYMBOL_DILATION2DBACKPROPFILTER 		310
#define SYMBOL_DILATION2DBACKPROPINPUT 		311
#define SYMBOL_ELU 		312
#define SYMBOL_FRACTIONALAVGPOOL 		313
#define SYMBOL_FRACTIONALMAXPOOL 		314
#define SYMBOL_FUSEDBATCHNORM 		315
#define SYMBOL_FUSEDBATCHNORMGRAD 		316
#define SYMBOL_FUSEDPADCONV2D 		317
#define SYMBOL_FUSEDRESIZEANDPADCONV2D 		318
#define SYMBOL_INTOPK 		319
#define SYMBOL_L2LOSS 		320
#define SYMBOL_LRN 		321
#define SYMBOL_LOGSOFTMAX 		322
#define SYMBOL_MAXPOOL 		323
#define SYMBOL_MAXPOOL3D 		324
#define SYMBOL_MAXPOOL3DGRAD 		325
#define SYMBOL_MAXPOOL3DGRADGRAD 		326
#define SYMBOL_MAXPOOLGRADGRAD 		327
#define SYMBOL_MAXPOOLGRADGRADWITHARGMAX 		328
#define SYMBOL_MAXPOOLWITHARGMAX 		329
#define SYMBOL_QUANTIZEDAVGPOOL 		330
#define SYMBOL_QUANTIZEDBATCHNORMWITHGLOBALNORMALIZATION 		331
#define SYMBOL_QUANTIZEDBIASADD 		332
#define SYMBOL_QUANTIZEDCONV2D 		333
#define SYMBOL_QUANTIZEDMAXPOOL 		334
#define SYMBOL_QUANTIZEDRELU 		335
#define SYMBOL_QUANTIZEDRELU6 		336
#define SYMBOL_QUANTIZEDRELUX 		337
#define SYMBOL_RELU 		338
#define SYMBOL_RELU6 		339
#define SYMBOL_SOFTMAX 		340
#define SYMBOL_SOFTMAXCROSSENTROPYWITHLOGITS 		341
#define SYMBOL_SOFTPLUS 		342
#define SYMBOL_SOFTSIGN 		343
#define SYMBOL_SPARSESOFTMAXCROSSENTROPYWITHLOGITS 		344
#define SYMBOL_TOPK 		345
#define SYMBOL_NOOP 		346
#define SYMBOL_DECODECSV 		347
#define SYMBOL_DECODEJSONEXAMPLE 		348
#define SYMBOL_DECODERAW 		349
#define SYMBOL_PARSEEXAMPLE 		350
#define SYMBOL_PARSESINGLESEQUENCEEXAMPLE 		351
#define SYMBOL_PARSETENSOR 		352
#define SYMBOL_STRINGTONUMBER 		353
#define SYMBOL_MULTINOMIAL 		354
#define SYMBOL_PARAMETERIZEDTRUNCATEDNORMAL 		355
#define SYMBOL_RANDOMGAMMA 		356
#define SYMBOL_RANDOMNORMAL 		357
#define SYMBOL_RANDOMPOISSON 		358
#define SYMBOL_RANDOMSHUFFLE 		359
#define SYMBOL_RANDOMUNIFORM 		360
#define SYMBOL_RANDOMUNIFORMINT 		361
#define SYMBOL_TRUNCATEDNORMAL 		362
#define SYMBOL_ADDMANYSPARSETOTENSORSMAP 		363
#define SYMBOL_ADDSPARSETOTENSORSMAP 		364
#define SYMBOL_DESERIALIZEMANYSPARSE 		365
#define SYMBOL_SERIALIZEMANYSPARSE 		366
#define SYMBOL_SERIALIZESPARSE 		367
#define SYMBOL_SPARSEADD 		368
#define SYMBOL_SPARSEADDGRAD 		369
#define SYMBOL_SPARSECONCAT 		370
#define SYMBOL_SPARSECROSS 		371
#define SYMBOL_SPARSEDENSECWISEADD 		372
#define SYMBOL_SPARSEDENSECWISEDIV 		373
#define SYMBOL_SPARSEDENSECWISEMUL 		374
#define SYMBOL_SPARSEREDUCESUM 		375
#define SYMBOL_SPARSEREDUCESUMSPARSE 		376
#define SYMBOL_SPARSEREORDER 		377
#define SYMBOL_SPARSERESHAPE 		378
#define SYMBOL_SPARSESOFTMAX 		379
#define SYMBOL_SPARSESPARSEMAXIMUM 		380
#define SYMBOL_SPARSESPARSEMINIMUM 		381
#define SYMBOL_SPARSESPLIT 		382
#define SYMBOL_SPARSETENSORDENSEADD 		383
#define SYMBOL_SPARSETENSORDENSEMATMUL 		384
#define SYMBOL_SPARSETODENSE 		385
#define SYMBOL_TAKEMANYSPARSEFROMTENSORSMAP 		386
#define SYMBOL_ASSIGN 		387
#define SYMBOL_ASSIGNADD 		388
#define SYMBOL_ASSIGNSUB 		389
#define SYMBOL_COUNTUPTO 		390
#define SYMBOL_DESTROYTEMPORARYVARIABLE 		391
#define SYMBOL_ISVARIABLEINITIALIZED 		392
#define SYMBOL_SCATTERADD 		393
#define SYMBOL_SCATTERDIV 		394
#define SYMBOL_SCATTERMUL 		395
#define SYMBOL_SCATTERNDADD 		396
#define SYMBOL_SCATTERNDSUB 		397
#define SYMBOL_SCATTERNDUPDATE 		398
#define SYMBOL_SCATTERSUB 		399
#define SYMBOL_SCATTERUPDATE 		400
#define SYMBOL_TEMPORARYVARIABLE 		401
#define SYMBOL_VARIABLE 		402
#define SYMBOL_ASSTRING 		403
#define SYMBOL_DECODEBASE64 		404
#define SYMBOL_ENCODEBASE64 		405
#define SYMBOL_REDUCEJOIN 		406
#define SYMBOL_STRINGJOIN 		407
#define SYMBOL_STRINGSPLIT 		408
#define SYMBOL_STRINGTOHASHBUCKET 		409
#define SYMBOL_STRINGTOHASHBUCKETFAST 		410
#define SYMBOL_STRINGTOHASHBUCKETSTRONG 		411
#define SYMBOL_SUBSTR 		412
#define SYMBOL_APPLYADADELTA 		413
#define SYMBOL_APPLYADAGRAD 		414
#define SYMBOL_APPLYADAGRADDA 		415
#define SYMBOL_APPLYADAM 		416
#define SYMBOL_APPLYCENTEREDRMSPROP 		417
#define SYMBOL_APPLYFTRL 		418
#define SYMBOL_APPLYGRADIENTDESCENT 		419
#define SYMBOL_APPLYMOMENTUM 		420
#define SYMBOL_APPLYPROXIMALADAGRAD 		421
#define SYMBOL_APPLYPROXIMALGRADIENTDESCENT 		422
#define SYMBOL_APPLYRMSPROP 		423
#define SYMBOL_RESOURCEAPPLYADADELTA 		424
#define SYMBOL_RESOURCEAPPLYADAGRAD 		425
#define SYMBOL_RESOURCEAPPLYADAGRADDA 		426
#define SYMBOL_RESOURCEAPPLYADAM 		427
#define SYMBOL_RESOURCEAPPLYCENTEREDRMSPROP 		428
#define SYMBOL_RESOURCEAPPLYFTRL 		429
#define SYMBOL_RESOURCEAPPLYGRADIENTDESCENT 		430
#define SYMBOL_RESOURCEAPPLYMOMENTUM 		431
#define SYMBOL_RESOURCEAPPLYPROXIMALADAGRAD 		432
#define SYMBOL_RESOURCEAPPLYPROXIMALGRADIENTDESCENT 		433
#define SYMBOL_RESOURCEAPPLYRMSPROP 		434
#define SYMBOL_RESOURCESPARSEAPPLYADADELTA 		435
#define SYMBOL_RESOURCESPARSEAPPLYADAGRAD 		436
#define SYMBOL_RESOURCESPARSEAPPLYADAGRADDA 		437
#define SYMBOL_RESOURCESPARSEAPPLYCENTEREDRMSPROP 		438
#define SYMBOL_RESOURCESPARSEAPPLYFTRL 		439
#define SYMBOL_RESOURCESPARSEAPPLYMOMENTUM 		440
#define SYMBOL_RESOURCESPARSEAPPLYPROXIMALADAGRAD 		441
#define SYMBOL_RESOURCESPARSEAPPLYPROXIMALGRADIENTDESCENT 		442
#define SYMBOL_RESOURCESPARSEAPPLYRMSPROP 		443
#define SYMBOL_SPARSEAPPLYADADELTA 		444
#define SYMBOL_SPARSEAPPLYADAGRAD 		445
#define SYMBOL_SPARSEAPPLYADAGRADDA 		446
#define SYMBOL_SPARSEAPPLYCENTEREDRMSPROP 		447
#define SYMBOL_SPARSEAPPLYFTRL 		448
#define SYMBOL_SPARSEAPPLYMOMENTUM 		449
#define SYMBOL_SPARSEAPPLYPROXIMALADAGRAD 		450
#define SYMBOL_SPARSEAPPLYPROXIMALGRADIENTDESCENT 		451
#define SYMBOL_SPARSEAPPLYRMSPROP 		452
#define SYMBOL_FACT 		453

//////////////////////////////////////////////////////////////////////////
// [v1.3] Add Symbol
#define SYMBOL_ISFINITE 		500
#define SYMBOL_COSH 		501
#define SYMBOL_SINH 		502
#define SYMBOL_DECODEBMP 		503
#define SYMBOL_SAMPLEDISTORTEDBOUNDINGBOXV2		504
#define SYMBOL_QUANTIZEDRESIZEBILINEAR		505
#define SYMBOL_LMDBREADER	506

#define SYMBOL_DEBUGGRADIENTIDENTITY 600
#define SYMBOL_GATHERV2	601
#define SYMBOL_PADV2 602
#define SYMBOL_FEEDTYPE	603

//////////////////////////////////////////////////////////////////////////
// [extension] Add symbol
#define SYMBOL_CONST				454
#define SYMBOL_RANDOMNORMAL_EX		456

#define SYMBOL_CONST_EX					700
#define SYMBOL_SPARSEFILLEMPTYROWS		701
#define SYMBOL_SPARSEFILLEMPTYROWSGRAD	702
#define SYMBOL_SPARSEREDUCEMAX			703
#define	SYMBOL_SPARSEREDUCEMAXSPARSE	704
#define	SYMBOL_SPARSESLICE				705
//////////////////////////////////////////////////////////////////////////

#define OUTPUT_TYPE_INPUT			0
#define OUTPUT_TYPE_OUTPUT			1
#define OUTPUT_TYPE_OUTPUTLIST		2
#define OUTPUT_TYPE_OPERATION		3

using namespace tensorflow;
using namespace tensorflow::ops;

struct OutputInfo
{
	int type;						// 노드의 ouput 타입
	void* pOutput;					// 노드의 output 주소
	public:OutputInfo()
	{
		type = OUTPUT_TYPE_OUTPUT;
		pOutput = nullptr;
	}
};

struct ObjectInfo
{
	std::string id;					// 그래픽 로직 블럭의 ID
	int     type;					// 그래픽 로직 블럭의 객체 타입
	std::string type_name;			// 객체의 타입의 문자열 이름
	void*   pObject;				// 그래픽 로직 블럭의 클랙스 포인터
	Json::Value param;				// 그래픽 로직 블럭의 JSON 파라미터 정보

	tensorflow::Scope* pScope;		// 그래픽 로직 블럭에 연결된 SCOPE 객체 포인터
	std::map<std::string, OutputInfo*> pMapOutputs;		// 그래픽 로직 블럭의 클래스의 Output 멤버 포인터 맵 리스트

	public:ObjectInfo()
	{
		type = SYMBOL_NONE;
		pObject = nullptr;
		pScope = nullptr;
	}
};

struct Fetch_Output
{
	std::vector<ObjectInfo*> fetch_object;				// ClientSession 객체의 fetch_output에 연결된 객체의 리스트
	std::vector<tensorflow::Output> fetch_outputs;		// ClientSession 객체의 fetch_output에 연결된 객체의 output 리스트
	std::vector<tensorflow::Operation> run_outputs;		// ClientSession 객체의 run_output에 연결된 객체의 operation 리스트
	std::vector<std::string> pin_names;					// 입력핀의 이름
};

struct Fetch_OutputList
{
	std::vector<ObjectInfo*> fetch_object;				// ClientSession 객체의 fetch_output에 연결된 객체의 리스트
	std::vector<tensorflow::OutputList> fetch_outputs;	// ClientSession 객체의 fetch_output에 연결된 객체의 output 리스트
	std::vector<std::string> pin_names;					// 입력핀의 이름
};

struct FetchInfo
{
	ObjectInfo* pSession;							// ClientSession 객체
	ClientSession::FeedType FeedType;				// feedtype

	Fetch_Output output;
	Fetch_OutputList output_list;

	std::map<std::string, ObjectInfo* > fetch_object_map;	// 연결선 MAP 관리.
	// Fetch_Output output_value;								// 연결선을 따라서 값을 업데이트 하는 객체 리스트
	// Fetch_OutputList output_value_list;						// 연결선을 따라서 값을 업데이트 하는 객체 리스트

	public:FetchInfo()
	{
		pSession = nullptr;
	}
};

struct FeedTypeObject
{
	Output *pOutput;
	Input::Initializer *pInitializer;
	public:FeedTypeObject()
	{
		pOutput = nullptr;
		pInitializer = nullptr;
	}
};


extern std::map<std::string, ObjectInfo* > m_ObjectMapList;
extern std::map<std::string, FetchInfo* > m_RunMapList;
extern Scope* m_pScope;										// set the current scope node pointer.

extern std::map<std::string, int>	m_SymbolList;

#endif